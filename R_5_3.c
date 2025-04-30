#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef char String[1024];

int main()
{
    String set;

    printf("1~9の数を入力してください\n");
    scanf("%s", set);
    int b = atoi(set);
    switch (b)
    {
    case 1:
    case 2:
        printf("バッテリー\n");
        /* code */
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        printf("内野手\n");
        /* code */
        break;
    case 7:
    case 8:
    case 9:
        printf("外野手\n");
        /* code */
        break;

    default:
        printf("入力された守備位置はありません\n");

        break;
    }
    return 0;
}