#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char String[1024];

int main(void)
{
    int b = 0;
    int a[6][6] = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 1, 2, 0, 1},
        {1, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1},
    };
    for (int i = 0; i < 6; i++)
    {

        for (int n = 0; n < 6; n++)
        {
            b = a[i][n];
            switch (b)
            {
            case 0:
                printf("・");
                /* code */
                break;
            case 1:
                printf("口");
                /* code */
                break;
            case 2:
                printf("下");
                /* code */
                break;

            default:
                break;
            }

            if (n == 5)
                printf("\n");

            /* code */
        }
    }

    return 0;
}