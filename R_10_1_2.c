#include <stdio.h>
#include <string.h>

void sub(char *ages)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d番目:%d\n", i + 1, *ages + i);
        /* code */
    }
}
int main(int argc, char const *argv[])
{
    char a[] = {1, 2, 3};
    char b[3];
    sub(&a[0]);
    memcpy(b, a, 3);
    sub(b);
    if (memcpy(b, a, 3))
        printf("正常にコピーされましたか？\n");
    return 0;
}
