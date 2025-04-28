#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char String[1024];

int main(void)
{
    int a[4][5] = {
        {123, 456, 789, 101, 121}, //[0][0~4]
        {312, 151, 617, 181, 920}, //[1][0~4]
        {212, 223, 242, 526, 272}, //[2][0~4]
        {829, 303, 132, 333, 435}  //[3][0~4]
    };
    printf("2字配列aの値を表示\n");

    for (int i = 0; i < 4; i++)
    {
        printf("a[%d][0-4]:", i);
        /* code */
        for (int n = 0; n < 5; n++)
        {
            printf("%d", a[i][n]);
            if (n == 4)
                printf("\n");
            else
                printf(",");

            /* code */
        }
    }

    return 0;
}