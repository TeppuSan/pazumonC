#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char String[1024];

int main(void)
{
    String strSatiety;
    typedef struct
    {
        String name;
        int satiety;
        int hp;
    } Player;

    Player p = {"", 0, 0};
    printf("Playerのパラメータを設定してください\n");
    printf("名前:");
    scanf("%s", p.name);
    printf("満腹度(MAX100):");
    scanf("%s", strSatiety);
    p.satiety = atoi(strSatiety);
    while (p.satiety < 0 || 100 < p.satiety)
    {
        printf("範囲外です、設定しなおしてください\n");
        printf("満腹度(MAX100):");
        scanf("%s", strSatiety);
        p.satiety = atoi(strSatiety);
    }
    srand((unsigned)time(NULL));
    p.hp = rand() % 1000;
    printf("..............\n");
    printf("あなたの名前は%sです\n", p.name);
    printf("HPは%dです\n", p.hp);
    if (p.satiety < 60)
        printf("満腹度は%d、おなか減ってますね\n", p.satiety);
    else
        printf("満腹度は%d、満腹ですね\n", p.satiety);

    return 0;
}