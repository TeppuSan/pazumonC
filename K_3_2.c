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
    printf("a足すbは%d\n", a + b);
    printf("a引くbは%d\n", a - b);
    printf("aかけるbは%d\n", a * b);
    printf("a割るbは%d\n", a / b);
    printf("a割るbの余り(剰余)は%d\n", a % b);
    return 0;
}