#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void printlntByAddress(int *dev)
{
    // void* 型は単にアドレスを格納する型
    printf("Address:%p\n", (void *)dev);
}

int main()
{
    // char moji = 'C'; //9_2の消費バイトの処理
    // int money = 300000;
    // char *mozu = &moji;
    // int *monezu = &money;
    // printf("消費メモリ%ld\n消費メモリ%ld\n消費メモリ%ld\n消費メモリ%ld\n", sizeof(moji), sizeof(mozu), sizeof(money), sizeof(monezu));

    int dev = 398;

    printlntByAddress(&dev);

    return 0;
}