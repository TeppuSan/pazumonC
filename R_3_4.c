#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char String[1024];

int main()
{
    int a;
    int b;
    int c;
    int d;
    String num;
    printf("カレンダーから縦に並んだ数字を3つ選び、その合計を入力してください\n");
    scanf("%s", num);
    a = atoi(num);
    b = a / 3;
    c = b - 7;
    d = b + 7;

    printf("選んだ数字は%dと%dと%dですね\n", c, b, d);
}