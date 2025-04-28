#include <stdio.h>

int main(void)
{
    enum
    {
        DAIKITI = 1,
        CHUKICHI = 10,
        KICHI = 100,
        KYO = 1000
    };
    printf("大吉:%d\n", DAIKITI);
    printf("中吉:%d\n", CHUKICHI);
    printf("吉:%d\n", KICHI);
    printf("凶:%d\n", KYO);
    return 0;
}