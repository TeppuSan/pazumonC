#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef char String[1024];

int main()
{
    int tama = 3000; // お年玉の金額
    int ringo = 120; // リンゴの値段
    int mikan = 400; // ミカンの値段
    int total = 0;   // 使いまわすためここで定義
    int i = 0;       // 全体で使うためここで定義
    for (i = 0; total <= tama - mikan; i++)
        total += mikan;
    // ミカンは6個入りのため、個数i*6の処理を入れる
    printf("みかん%d個、余りは%d円\n", i * 6, tama - total);
    // totalの初期化処理
    total = 0;
    for (i = 0; total <= tama - ringo; i++)
        total += ringo;
    printf("りんご%d個、余りは%d円\n", i, tama - total);
    return 0;
}