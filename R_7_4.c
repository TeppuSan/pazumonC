#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef char String[1024];

int main()
{
    String set;
    int b = 0;
    printf("***数あてゲーム(レベル2)***\n3桁の数字を当ててください\nただし各桁の数字は重複しません\n");
    srand((unsigned)time(NULL));
    int answer[3];
    int t = 0;
    int in = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int n = 0; n < i; n++)
        {
            do
            {
                in = 0;
                t = rand() % 10;

                if (answer[n] == t)
                    in = 1;
                else
                    answer[i] = t;

                /* code */
            } while (in);

            /* code */
        }

        /* code */
    }

    for (int nt = 0; nt < 3; nt++)
    {
        printf("%d", answer[nt]);
        /* code */
    }

    // scanf("%s", set);
    // b = atoi(set);
    // printf("%d回めであたったよ!\n", i);

    printf("***GAMEOVER***\n");

    return 0;
}