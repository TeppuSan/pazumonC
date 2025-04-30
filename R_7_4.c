#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef char String[1024];

int main()
{
    String set;
    printf("***数あてゲーム(レベル2)***\n3桁の数字を当ててください\nただし各桁の数字は重複しません\n");
    srand((unsigned)time(NULL));
    int size = 3;
    int input[size];
    int answer[size];
    int contenue;
    int t = 0;
    int in = 0;
    int hit = 0;
    int blow = 0;

    for (int i = 0; i < size; i++)
    {
        do
        {
            in = 0;
            t = rand() % 10;
            for (int n = 0; n < i; n++)
                if (answer[n] == t)
                    in = 1;
        } while (in);

        answer[i] = t;
    }

    do
    {
        hit = 0;
        blow = 0;
        for (int nt = 0; nt < size; nt++)
        {
            printf("%d\n", answer[nt]);
            /* code */
        }

        for (int i = 0; i < size; i++)
        {
            scanf("%s", set);
            input[i] = atoi(set);
        }
        for (int i = 0; i < size; i++)
        {
            for (int n = 0; n < size; n++)
            {
                if (answer[i] == input[n])
                {
                    if (i == n)
                        hit++;
                    else
                        blow++;
                }

                /* code */
            }
        }
        printf("%dヒット%dブロー\n", hit, blow);
        if (hit != 3)
        {
            printf("続けますか?(0終了: 0以外の数字:続ける)>\n");
            scanf("%s", set);
            contenue = atoi(set);
            if (contenue == 0)
                return 0;
            /* code */
        }

        /* code */
    } while (hit != 3);

    // printf("%d回めであたったよ!\n", i);

    printf("***GAMECLEAR***\n");

    return 0;
}