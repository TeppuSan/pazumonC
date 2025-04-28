#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char String[1024];

int calcHp(int seed, int min, int max)
{
    int hp = 0;
    if (seed == 0)
        srand((unsigned)time(NULL));
    else
        srand(seed);

    hp = (rand() % (max - min + 1)) + min;
    return hp;
}

int main(void)
{
    String strSatiety;
    typedef struct
    {
        String name;
        int satiety;
        int hp;
        int atk;
    } Player;

    typedef struct
    {
        String name;
        int hp;
        int atk;
    } Enemy;

    Player p = {"", 0, 0, 0};
    Enemy e = {"", 0, 0};
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

    printf("\nEnemyの名前を設定してください\n");
    printf("名前:");
    scanf("%s", e.name);

    int seed = p.satiety;

    p.hp = calcHp(p.satiety, 100, 500);
    p.atk = rand() % 101;
    e.hp = rand() % 1000;
    e.atk = rand() % 101;
    printf("..............\n");
    printf("あなたの名前は%sです\n", p.name);
    printf("HPは%d、攻撃は%dです\n", p.hp, p.atk);
    if (p.satiety < 60)
        printf("満腹度は%d、おなか減ってますね\n", p.satiety);
    else
        printf("満腹度は%d、満腹ですね\n", p.satiety);
    printf("\n敵の名前は%sです\n", e.name);
    printf("HPは%d、攻撃は%dです\n", e.hp, e.atk);
    if (p.atk >= e.atk)
        printf("\n攻めよう\n");
    else
        printf("\n逃げよう\n");
    return 0;
}