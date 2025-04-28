#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char String[1024];

/**
 * @brief バトル通知を表示する巻数
 *
 * @param i 数値
 */
void doBattle(int i)
{

    const char *Mname[5] = {
        "スライム",
        "ゴブリン",
        "オオコウモリ",
        "ウェアウルフ",
        "ドラゴン"};

    printf("%sが現れた!\n", Mname[i]);
    printf("%sを倒した!\n", Mname[i]);
}

int goDungeon(int i, const char *name)
{
    printf("%sはダンジョンに到着した\n", name);

    for (i = 0; i < 5; i++)
    {
        doBattle(i);
    }
    printf("%sはダンジョンを制覇した\n", name);
    return i;
}

// args引数の数
// argvが配列
int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 1) // 引数が1である場合のエラー処理
    {
        printf("エラー:プレイヤー名を指定して起動してください\n");
        return 0;
    }
    printf("*** Puzzle & Monsters ***\n");
    // 1から始める理由は./a.outが引数として認識されるため

    i = goDungeon(i, argv[1]);

    printf("*** GAME CLEARED ***\n");
    printf("倒したモンスター数=%d\n", i);

    return 0;
}