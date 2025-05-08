#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h> /* pow */

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

// MAX_GEMS
typedef enum
{
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N
} MAX_GEMS;

double ELEMENT_BOOST[4][4] = {
    // 火　水　風　土
    {1.0, 0.5, 2.0, 1.0}, // 火
    {2.0, 1.0, 1.0, 0.5}, // 水
    {0.5, 1.0, 1.0, 2.0}, // 風
    {1.0, 2.0, 0.5, 1.0}  // 土
};

// ElementSymbol
// Elementの値によってシンボルを返す
const char *getElement_Symbol(Element e)
{
    const char *symbols[] = {
        "$", // FIRE
        "~", // WATER
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
    char *player; // playerネームの格納
    int MAXhp;    // 最大HP
    int hp;       // HP
    int def;      // 防御力
    int size;     // モンスター構造体の数
} Party;

// BattleField構造体
typedef struct
{
    Party *player;
    Monster *Enemy;
    MAX_GEMS *gems;
} BattleField;

// BanishInfo
typedef struct
{
    Element ele;
    int start;
    int count;
    /* data */
} BanishInfo;

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

// ここからダメージ処理

// comb補正用の関数
double combculc(BanishInfo *bani, int comb)
{
    double culc = 1.5 ^ (bani->count - 3 + comb);
}

// ダメージの+=10%のブレを出す関数
double blurDamege(double Damege)
{
    double blur = 0.9 + (rand() / (double)RAND_MAX) * (1.1 - 0.9);
    double newDamage = Damege * blur;
    return newDamage;
}

// 回復地の計算
int calcRecoverDamage(BattleField *BF, BanishInfo *bani, int comb)
{
    double calcRec = 20 * 1.5;
    calcRec = blurDamege(calcRec);
    return (int)calcRec;
}

// 回復の表示と最大値を超えた処理
void doRecover(BattleField *BF, BanishInfo *bani, int comb)
{
    int nowhp = BF->player->hp;
    int heal = calcRecoverDamage(BF, bani, comb);
    BF->player->hp += heal;
    if (BF->player->hp > BF->player->MAXhp)
    {
        heal = BF->player->MAXhp - nowhp;
        BF->player->hp = BF->player->MAXhp;
    }
    printf("%d回復した\n", heal);
}
// 敵側の攻撃計算
int calcEnemyAttack(BattleField *BF)
{
    double dame = 0;
    dame = (BF->Enemy->atk - BF->player->def);
    dame = blurDamege(dame);
    return (int)dame;
}

// 敵側の攻撃の処理
void onEnemyAttack(BattleField *BF)
{
    int dame = calcEnemyAttack(BF);
    if (dame <= 0)
        dame = 1;
    printf("【%s】の攻撃で%dのダメージを受けた\n\n", PrintMonsterName(BF->Enemy), dame);
    BF->player->hp -= dame;
    return;
}
// player側の攻撃計算
int calcAttack(BattleField *BF, BanishInfo *bani, int i, int comb)
{
    double dame = 0;
    dame = (BF->player->par[i].atk - BF->Enemy->def) * ELEMENT_BOOST[BF->player->par[i].element][BF->Enemy->element];
    dame = blurDamege(dame);
    return (int)dame;
}

// player側の攻撃処理
void onAttack(BattleField *BF, BanishInfo *bani, int comb)
{
    int dame = 0;

    for (int i = 0; i < BF->player->size; i++)
    {
        if (bani->ele == BF->player->par[i].element)
        {
            dame = calcAttack(BF, bani, i, comb);
            if (dame <= 0)
                dame = 1;
            BF->Enemy->hp -= dame;
            if (comb == 1)
                printf("【%s】の攻撃で%dのダメージを与えた\n\n", PrintMonsterName(&BF->player->par[i]), dame);
            else
                printf("【%s】の攻撃で%dのダメージを与えた \x1b[47m %d COMBO!\x1b[49m\n\n", PrintMonsterName(&BF->player->par[i]), dame, comb);
        }
    }
    return;
}

// Gem関連

// gemに色と記号をつける関数
void printGem(BattleField *BF, int i)
{
    int color = getElement_color(BF->gems[i]);
    const char *symbol = getElement_Symbol(BF->gems[i]);
    printf("\x1b[4%dm%s\x1b[49m ", color, symbol);
}

// gemの情報を表示する巻数
void printGems(BattleField *BF)
{
    for (int i = 0; i <= N; i++)
        printGem(BF, i);
    printf("\n");
}

// gemの情報を格納する関数
void fillGems(BattleField *BF)
{
    for (int i = 0; i <= N; i++)
    {
        BF->gems[i] = rand() % EMPTY;
    }
}

// gemの移動をする関数
void swapGem(BattleField *BF, int cmd1)
{
    int dmc = cmd1 - 65;               // 配列指定用
    int swap = BF->gems[dmc];          // 指定した配列の値をいれる
    BF->gems[dmc] = BF->gems[dmc + 1]; // 指定された配列より右の値を取得して指定した配列に入れる
    BF->gems[dmc + 1] = swap;          // 右の値に指定した配列の値を入れている
    // printGems(BF);
}

// gemの移動やgemの移動を表示する関数
void moveGems(int cmd1, int cmd2, BattleField *BF, BanishInfo *bani)
{
    if (cmd1 < cmd2)
    {
        for (int i = cmd1; i < cmd2; i++)
        {
            swapGem(BF, i);
            printf("\n");
            if (bani->count == 0)
            {
                printGems(BF);
                printf("\n");
            }
        }
    }
    else
    {
        for (int i = cmd1 - 1; i > cmd2 - 1; i--)
        {
            // printf("I:%d\n", i);
            if (i < 78)
            {
                swapGem(BF, i);
                if (bani->count == 0)
                {
                    printGems(BF);
                    printf("\n");
                }
            }
        }
    }
}

// 空白がある場合の左側への移動処理
void shiftGems(BattleField *BF, BanishInfo *bani)
{
    printGems(BF);

    for (int i = bani->count; i > 0; i--)
    {
        for (int n = bani->start - 1; n < N; n++)
        {
            moveGems(n + 65 + i, n + 64 + i, BF, bani);
        }
        printf("\n");
        printGems(BF);
    }
}

// 空白がある場所へのランダムgem生成
void spawnGems(BattleField *BF, BanishInfo *bani)
{
    printf("\n");
    for (int i = 0; i <= N; i++)
    {
        if (BF->gems[i] == EMPTY)
            BF->gems[i] = rand() % EMPTY;
    }
    printGems(BF);
}

// 3つ以上並んでいる場合、空その並んでいる箇所を空白にする処理
void banishGems(BattleField *BF, BanishInfo *bani, int comb)
{
    printGems(BF);
    for (int i = 0; i < bani->count; i++)
    {
        BF->gems[i + bani->start - 1] = 5;
        if (bani->start == 0)
            BF->gems[bani->count - 1] = 5;
    }
    if (bani->count != 0)
    {
        printGems(BF);
        if (bani->ele <= EARTH)
        {
            onAttack(BF, bani, comb);
        }
        else if (bani->ele == LIFE)
        {
            doRecover(BF, bani, comb);
        }
    }
}

// gemの属性と個数を調べる処理
void countGem(BattleField *BF)
{
    int FI = 0;
    int WA = 0;
    int WI = 0;
    int EA = 0;
    int LI = 0;
    int EM = 0;
    for (int i = 0; i < N + 1; i++)
    {
        switch (BF->gems[i])
        {
        case FIRE:
            FI++;
            break;
        case WATER:
            WA++;
            break;
        case WIND:
            WI++;
            break;
        case EARTH:
            EA++;
            break;
        case LIFE:
            LI++;
            break;
        case EMPTY:
            EM++;
            break;

        default:
            break;
        }
    }
    printf("火%d,水%d,風%d,土%d,命%d,無%d\n", FI, WA, WI, EA, LI, EM);
}

// gemが3つ以上並んでいるかを調べる処理
void checkBanishable(BattleField *BF, BanishInfo *bani)
{
    int start = 0;
    for (int i = 1; i < N + 1; i++)
    {
        if (BF->gems[i] != EMPTY)
        {

            if (BF->gems[i - 1] == BF->gems[i])
            {
                bani->ele = BF->gems[i];
                if (bani->count == 0)
                {
                    bani->count = 2;
                    bani->start = i;
                }
                else
                    bani->count++;
            }
            else if (bani->count >= 3)
            {
                printf("length%d\n", bani->count);
                return;
            }
            else
            {
                bani->start = start;
                bani->count = 0;
            }
            /* code */
        }
    }
}

// gemの消滅や移動を狩りする関数
void evaluateGem(char playcommand1, char playcommand2, BattleField *BF)
{
    BanishInfo bani = {EMPTY, 0, 0};
    int comb = 0;
    int cmd1 = (int)playcommand1;
    int cmd2 = (int)playcommand2;
    moveGems(cmd1, cmd2, BF, &bani);
    do
    {
        bani.count = 0;
        bani.ele = EMPTY;
        checkBanishable(BF, &bani);
        printf("Gem%d,start%d,length%d\n", bani.ele, bani.start, bani.count);
        if (bani.count > 0)
        {
            comb++;
            printf("Gem%d,start%d,length%d\n", bani.ele, bani.start, bani.count);

            banishGems(BF, &bani, comb);
            shiftGems(BF, &bani);
            /* code */
            /* code */
        }

    } while (bani.count > 0);

    spawnGems(BF, &bani);
    countGem(BF);
}

// party情報

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
    p->MAXhp = partyhp;            // p.MAXhpにhpの値を入れている
    p->hp = partyhp;               // p.hpにhpの値を入れている
    p->def = partydef;             // p.defにdefの値を入れている
}

// 入れられた文字が正しいか判定する巻数
bool checkValidCommand(char playcommand1, char playcommand2, char playcommand3)
{
    int check = 0; // check判定の初期値
    // 各文字がA〜Nか判定
    if (playcommand1 == playcommand2 || playcommand3 != '\n' ||
        (playcommand1 < 'A' || playcommand1 > 'N') ||
        (playcommand2 < 'A' || playcommand2 > 'N'))
        check = 1;
    return check;
}
// バトルフィールドの情報を表示する巻数
void showBattleField(BattleField *BF)
{
    printf("--------------------\n");
    printf("     %s     \n", PrintMonsterName(BF->Enemy));
    printf("    HP=%d/%d    \n\n\n", BF->Enemy->hp, BF->Enemy->MAXhp);
    for (int i = 0; i < BF->player->size; i++)
    {
        const char *plname = PrintMonsterName(&BF->player->par[i]);
        printf(" %s ", plname);
    }
    printf("\n    HP=%d/%d    \n", BF->player->hp, BF->player->MAXhp);
    printf("--------------------\n");
    for (int i = 0; i < N + 1; i++)
        printf("%c ", (char)(i + 65));
    printf("\n");
    printGems(BF);
    printf("\n--------------------\n");
}
// パーティの詳細情報を表示する巻数
void showParty(const Party *p)
{
    printf("<パーティ編成>(HP=%d)----------\n", p->hp);
    for (int i = 0; i < p->size; i++)
    {
        const char *name = PrintMonsterName(&p->par[i]);
        printf("%s HP=%d 攻撃=%d 防御=%d\n",
               name, p->par[i].hp, p->par[i].atk, p->par[i].def);
    }
    printf("--------------------\n");
}

// ターン処理

// 敵側のターンの処理
void onEnemyTurn(BattleField *BF)
{
    printf("【%s】のターン\n", PrintMonsterName(BF->Enemy));
    onEnemyAttack(BF);
    return;
}

// playerのターンの処理
void onPlayerTurn(BattleField *BF)
{
    int check; // check判定の受け取り用
    char playcommand1, playcommand2, playcommand3;
    printf("【%s】のターン\n", BF->player->player);
    showBattleField(BF);
    do
    {
        printf("コマンド?>");
        // 半角スペースを入れている理由は改行で反応させなくするため
        scanf(" %c%c%c", &playcommand1, &playcommand2, &playcommand3);
        check = checkValidCommand(playcommand1, playcommand2, playcommand3);
    } while (check);
    evaluateGem(playcommand1, playcommand2, BF);
    return;
}

// バトルの処理の関数
void doBattle(Monster *mos, Party *p)
{
    printf("%sが現れた!\n",
           PrintMonsterName(mos));
    BattleField BF = {
        p,
        mos,
    };
    BF.gems = malloc(sizeof(Element) * (N + 1));
    fillGems(&BF);
    while (BF.Enemy->hp > 0)
    {
        onPlayerTurn(&BF);
        if (BF.Enemy->hp <= 0)
            printf("%sを倒した!\n", PrintMonsterName(mos));
        else
            onEnemyTurn(&BF);
        if (BF.player->hp <= 0)
            return;
    }
    printf("%sはさらに奥に進んだ・・・\n", BF.player->player);
    printf("====================\n");
    free(BF.gems);
    return;
}

// ダンジョン関連の関数
int goDungeon(const Dungeon *h, Party *p)
{
    int b = 0;
    printf("%sのパーティはダンジョンに到着した\n", p->player);
    showParty(p);
    for (b = 0; b < h->size; b++)
    {
        doBattle(&h->mos[b], p);
        if (p->hp <= 0)
        {
            printf("%sはダンジョンから逃げ出した・・・\n", p->player);
            return b;
        }
    }
    printf("%sはダンジョンを制覇した\n", p->player);
    return b;
}

// args引数の数
// argvが配列
int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));
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
    // PlayName
    p.player = argv[1];
    if (argc == 1) // 引数が1である場合のエラー処理
    {
        printf("エラー:プレイヤー名を指定して起動してください\n");
        return 0;
    }
    printf("*** Puzzle & Monsters ***\n");
    // 1から始める理由は./a.outが引数として認識されるため
    oeganizeParty(&p);
    wincount = goDungeon(&h, &p);
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