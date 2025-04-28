#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char String[1024];

// Element
typedef enum
{
    火, // 0
    水, // 1
    風, // 2
    土, // 3
    命, // 4
    無  // 5
} Element;

// ElementSymbol
// Elementの値によってシンボルを返す
const char *getElement_Symbol(Element e)
{
    const char *symbols[] = {
        "$", // 火
        "-", // 水
        "@", // 風
        "#", // 土
        "&", // 命
        " ", // 無
    };
    if (e >= 火 && e <= 無)
        return symbols[e];
    return "?";
};

// Elementcolor
// Elementの値によってカラーコードを返す
int getElement_color(Element e)
{
    int Element_color[6] = {
        1, // 火
        6, // 水
        2, // 風
        3, // 土
        5, // 命
        0  // 無
    };
    if (e >= 火 && e <= 無)
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
Monster s = {"スライム", 100, 100, 水, 10, 5};
Monster g = {"ゴブリン", 200, 200, 土, 20, 15};
Monster o = {"オオコウモリ", 300, 300, 風, 30, 25};
Monster w = {"ウェアウルフ", 400, 400, 風, 40, 30};
Monster d = {"ドラゴン", 800, 800, 火, 50, 40};

// printf("モンスターネーム%s\nMAXhp%d\nhp%d\n属性%d\natk%d\ndef%d\n", s.name, s.MAXhp, s.hp, s.element, s.atk, s.def);

// Dungeon構造体
typedef struct
{
    Monster *mos; // モンスター構造体のポインタ
    int size;     // モンスター構造体の数
} Dungeon;

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

// バトルの処理の関数
void doBattle(const Monster *mos)
{
    const char *name = PrintMonsterName(mos);

    printf("%sが現れた!\n", name);
    printf("%sを倒した!\n", name);
}

// ダンジョン関連の関数
void goDungeon(const Dungeon *h, const char *name)
{
    printf("%sはダンジョンに到着した\n", name);

    for (int b = 0; b < h->size; b++)
    {
        doBattle(&h->mos[b]);
    }
    printf("%sはダンジョンを制覇した\n", name);
    return;
}

// args引数の数
// argvが配列
int main(int argc, char **argv)
{
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

    // printf("モンスターネーム%s\nMAXhp%d\nhp%d\n属性%d\natk%d\ndef%d\n", s.name, s.MAXhp, s.hp, s.element, s.atk, s.def);

    // int i = 0;
    // printf("\x1b[34mエレメントシンボル%s\x1b[39m", getElement_Symbol(水));
    // printf("エレメントカラーナンバー%d", getElement_color(水));

    if (argc == 1) // 引数が1である場合のエラー処理
    {
        printf("エラー:プレイヤー名を指定して起動してください\n");
        return 0;
    }
    printf("*** Puzzle & Monsters ***\n");
    // 1から始める理由は./a.outが引数として認識されるため

    goDungeon(&h, argv[1]);

    printf("*** GAME CLEARED ***\n");
    printf("倒したモンスター数=%d\n", h.size);
    // メモリの開放
    free(h.mos);

    return 0;
}