#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    int scores[5] = {88, 61, 90, 75, 93};
    int total = 0;
    int best = scores[0];
    int worst = scores[0];
    float average = 0;
    for (int i = 0; i < 5; i++)
    {
        if (best < scores[i])
            best = scores[i];

        if (worst > scores[i])
            worst = scores[i];

        total += scores[i];

        /* code */
    }
    average = (float)total / 5;

    printf("最高点%d最低点%d平均点%.1f\n", best, worst, average);

    return 0;
}
