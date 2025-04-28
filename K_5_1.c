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
    if (a == b)
        printf("2つの値は等しい\n");
    else if (a > b)
        printf("大きいほうは%d小さいほうは%d\n", a, b);
    else
        printf("大きいほうは%d小さいほうは%d\n", b, a);
    return 0;
}