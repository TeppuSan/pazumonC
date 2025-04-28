#include <stdio.h>
#include <stdlib.h>

typedef char String[1024];

int main(void)
{
    printf("何月ですか?:");
    String A;
    scanf("%s", A);
    int a = atoi(A);
    switch (a)
    {
    case 3:
    case 4:
    case 5:
        printf("%d月は春です\n", a);
        break;
    case 6:
    case 7:
    case 8:
        printf("%d月は夏です\n", a);
        break;
    case 9:
    case 10:
    case 11:
        printf("%d月は秋です\n", a);
        break;
    case 12:
    case 1:
    case 2:
        printf("%d月は冬です\n", a);
        break;
    default:
        printf("存在しない月です\n");
        break;
    }
    return 0;
}