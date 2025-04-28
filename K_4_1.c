#include <stdio.h>
#include <stdlib.h>

typedef char String[1024];

int main(void)
{
    printf("2つの整数を入力してください\n");
    String A;
    printf("整数a:");
    scanf("%s", A);
    String B;
    printf("整数b:");
    scanf("%s", B);
    int a = atoi(A);
    int b = atoi(B);
    int c = a % b;
    if (c)
        printf("aはbの倍数ではありません\n");
    else
        printf("aはbの倍数です\n");
    return 0;
}