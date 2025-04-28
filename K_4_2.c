#include <stdio.h>
#include <stdlib.h>

typedef char String[1024];

int main(void)
{
    printf("正の整数を入力してください\n");
    String A;
    printf("整数a:");
    scanf("%s", A);
    int a = atoi(A);
    int b = 1;
    int c = 0;
    while (a - 1 >= b)
    {
        printf("%d", b);
        b = b + 1;
        c = b % 10;
        if (c == 1)
            printf("\n");
        else
            printf(",");
    }
    printf("%d\n", a);
    return 0;
}