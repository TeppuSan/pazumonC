#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char String[1024];

// Element
typedef enum
{
    FIRE,  // 0
    WATER, // 1
    WIND,  // 2
    EARTH, // 3
    LIFE,  // 4
    EMPTY  // 5
} Element;

// ElementSymbol
// Elementの値によってシンボルを返す
const char *getElement_Symbol(Element e)
{
    const char *symbols[] = {
        "$", // FIRE
        "-", // WATER
        "@", // WIND
        "#", // EARTH
        "&", // LIFE
        " ", // EMPTY
    };
    if (e >= FIRE && e <= EMPTY)
        return symbols[e];
    return "?";
};

// Elementcolor
// Elementの値によってカラーコードを返す
int getElement_color(Element e)
{
    int Element_color[6] = {
        1, // FIRE
        6, // WATER
        2, // WIND
        3, // EARTH
        5, // LIFE
        0  // EMPTY
    };
    if (e >= FIRE && e <= EMPTY)
        return Element_color[e];
    return -1;
};

// Monster構造体
typedef struct
{
    String name;     // 名前
    int MAXhp;       // 最大HP
    int hp;          // HP
    Element element; // 属性
    int atk;         // 攻撃力
    int def;         // 防御力
} Monster;
// 敵用
Monster s = {"スライム", 100, 100, WATER, 10, 5};
Monster g = {"ゴブリン", 200, 200, EARTH, 20, 15};
Monster o = {"オオコウモリ", 300, 300, WIND, 30, 25};
Monster w = {"ウェアウルフ", 400, 400, WIND, 40, 30};
Monster d = {"ドラゴン", 800, 800, FIRE, 50, 40};

// 味方用
Monster suzaku = {"朱雀", 150, 150, FIRE, 25, 10};
Monster seiryuu = {"青龍", 150, 150, WIND, 15, 10};
Monster byakko = {"白虎", 150, 150, EARTH, 20, 5};
Monster genbu = {"玄武", 150, 150, WATER, 20, 15};

// Dungeon構造体
typedef struct
{
    Monster *mos; // モンスター構造体のポインタ
    int size;     // モンスター構造体の数
} Dungeon;

// Party構造体
typedef struct
{
    Monster *par; // モンスター構造体のポインタ
    int MAXhp;    // 最大HP
    int hp;       // HP
    int def;      // 防御力
    int size;     // モンスター構造体の数
} Party;

// printf("モンスターネーム%s\nMAXhp%d\nhp%d\n属性%d\natk%d\ndef%d\n", s.name, s.MAXhp, s.hp, s.element, s.atk, s.def);

// party pのポイントを取得して
void oeganizeParty(Party *p)
{
    int partyhp = 0;
    int partydef = 0;
    for (int i = 0; i < p->size; i++)
    {
        partyhp += p->par[i].hp;   // partyhpにp.par[i].hpにてHPを追加している
        partydef += p->par[i].def; // partydefにp.par[i].defにてDEFを追加している
    }
    partydef = partydef / p->size; // partydefの値を平均値にしている
    p->hp = partyhp;               // p.hpにhpの値を入れている
    p->def = partydef;             // p.defにdefの値を入れている
}

// モンスターの名前に記号と色を付ける関数
const char *PrintMonsterName(const Monster *mos)
{
    static char colorName[2048];                          // 要素の大きさ指定
    int color = getElement_color(mos->element);           // モンスターの属性を参照してカラーコードを取得
    const char *symbol = getElement_Symbol(mos->element); // モンスターの属性を参照してシンボルを取得
    // colorNameにsizeof(colorName)で大きさ指定し、""の中身を入れる
    snprintf(colorName, sizeof(colorName), "\x1b[3%dm%s%s%s\x1b[39m", color, symbol, mos->name, symbol);
    return colorName; // colorNameの値を返す
}

void showParty(const Party *p)
{
    printf("<パーティ編成>(HP=%d)----------\n", p->hp);
    for (int i = 0; i < p->size; i++)
    {
        const char *name = PrintMonsterName(&p->par[i]);
        printf("%s HP=%d 攻撃=%d 防御=%d\n",
               name, p->par[i].hp, p->par[i].atk, p->par[i].def);
        /* code */
    }
    printf("--------------------\n");
}

// 敵側の攻撃の処理
void onEnemyAttack(Monster *mos, Party *p, const char *PlayName, const char *name)
{
    printf("【%s】の攻撃で80のダメージを受けた\n", name);
    p->hp -= 80;
    return;
}

// 敵側のターンの処理
void onEnemyTurn(Monster *mos, Party *p, const char *PlayName, const char *name)
{
    printf("【%s】のターン\n", name);
    onEnemyAttack(mos, p, PlayName, name);
    return;
}

// player側の攻撃処理
void onAttack(Monster *mos, Party *p, const char *PlayName)
{

    printf("【%s】の攻撃で100のダメージを与えた\n", PlayName);
    mos->hp -= 109;
    return;
}
// playerのターンの処理
void onPlayerTurn(Monster *mos, Party *p, const char *PlayName)
{
    printf("【%s】のターン\n", PlayName);
    onAttack(mos, p, PlayName);

    return;
}

// バトルの処理の関数
void doBattle(Monster *mos, Party *p, const char *PlayName)
{
    const char *name = PrintMonsterName(mos);

    printf("%sが現れた!\n", name);
    while (mos->hp >= 0)
    {
        onPlayerTurn(mos, p, PlayName);
        if (mos->hp <= 0)
            printf("%sを倒した!\n", name);
        else
            onEnemyTurn(mos, p, PlayName, name);
        if (p->hp <= 0)
            return;
    }
    printf("%sはさらに奥に進んだ・・・\n", PlayName);
    printf("====================\n");
    return;
}

// ダンジョン関連の関数
int goDungeon(const Dungeon *h, const char *name, Party *p)
{
    int b = 0;
    printf("%sのパーティはダンジョンに到着した\n", name);

    showParty(p);

    for (b = 0; b < h->size; b++)
    {
        doBattle(&h->mos[b], p, name);
        if (p->hp <= 0)
        {
            printf("%sはダンジョンから逃げ出した・・・\n", name);
            return b;
        }
    }
    printf("%sはダンジョンを制覇した\n", name);
    return b;
}

// args引数の数
// argvが配列
int main(int argc, char **argv)
{
    int wincount = 0;

    // Dungeon構造体のhを設定
    Dungeon h;
    // hの大きさの設定
    h.size = 5;
    // hのメモリの大きさの設定
    h.mos = malloc(sizeof(Monster) * h.size);
    if (h.mos == NULL)
    {
        printf("メモリ失敗");
        return -1;
        /* code */
    }
    // 配列格納
    h.mos[0] = s;
    h.mos[1] = g;
    h.mos[2] = o;
    h.mos[3] = w;
    h.mos[4] = d;

    // Party構造体のpを設定
    Party p;
    // pの大きさの設定
    p.size = 4;
    // pのメモリの大きさの設定
    p.par = malloc(sizeof(Monster) * p.size);
    if (p.par == NULL)
    {
        printf("メモリ失敗");
        return -1;
        /* code */
    }
    // 配列格納
    p.par[0] = suzaku;
    p.par[1] = seiryuu;
    p.par[2] = byakko;
    p.par[3] = genbu;

    // printf("モンスターネーム%s\nMAXhp%d\nhp%d\n属性%d\natk%d\ndef%d\n", s.name, s.MAXhp, s.hp, s.element, s.atk, s.def);

    // int i = 0;
    // printf("\x1b[34mエレメントシンボル%s\x1b[39m", getElement_Symbol(WATER));
    // printf("エレメントカラーナンバー%d", getElement_color(WATER));

    if (argc == 1) // 引数が1である場合のエラー処理
    {
        printf("エラー:プレイヤー名を指定して起動してください\n");
        return 0;
    }
    printf("*** Puzzle & Monsters ***\n");
    // 1から始める理由は./a.outが引数として認識されるため

    oeganizeParty(&p);

    wincount = goDungeon(&h, argv[1], &p);

    if (p.hp <= 0)
        printf("*** GAME OVER ***\n");
    else
        printf("*** GAME CLEARED ***\n");
    printf("倒したモンスター数=%d\n", wincount);
    // メモリの開放
    free(p.par);
    free(h.mos);

    return 0;
}