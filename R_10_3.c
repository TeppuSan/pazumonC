#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *sub(char *ages)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d番目:%d\n", i + 1, *(ages + i));
        /* code */
    }
}
int main(int argc, char const *argv[])
{
    char a[] = {1, 2, 3};
    char *b = (char *)malloc(3);
    memcpy(b, a, 3);

    sub(a);
    sub(b);
    if (memcpy(b, a, 3))
        printf("正常にコピーされましたか？\n");
    free(b);
    return 0;
}
