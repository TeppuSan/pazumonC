#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef char String[1024];

int main()
{
    String set;
    int temp = 30;
    int b;
    do
    {

        printf("現在の設定温度%d\n", temp);
        printf("暑いですか?Yes=1 No=0\n");
        scanf("%s", set);
        b = atoi(set);
        if (b != 1)
        {
            printf("設定を終了します\n");
            return 0;
        }
        else
        {
            temp -= 1;
        }
        /* code */
    } while (b == 1);
    return 0;
}