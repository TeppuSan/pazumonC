#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef char String[1024];

int main()
{
    String set;
    int chance = 4;
    int b = 0;
    printf("***数あてゲーム(レベル1)***\n回答のチャンスは%d回までです\n", chance);
    srand((unsigned)time(NULL));
    int answer = rand() % 10;

    for (int i = 1; i - 1 < chance; i++)
    {
        scanf("%s", set);
        b = atoi(set);

        if (answer == b)
        {
            printf("%d回めであたったよ!\n", i);
            return 0;
            /* code */
        }
        printf("はずれ!\n");
        if (answer < b)
            printf("おおきすぎるよ!!\n");
        else
            printf("ちいさすぎるよ!!\n");

        /* code */
    }

    printf("答えは%dだよ!\n", answer);
    printf("***GAMEOVER***\n");

    return 0;
}