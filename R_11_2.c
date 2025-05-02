#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char String[1024];

int main(int argc, char const *argv[])
{
    char ages[1024] = {19, 21, 29, 29};
    char a[] = {49, 50, 51, 52, 53, 0};
    char b[] = "12345";
    int lena = strlen(a);
    int lenb = strlen(b);
    int cmp = strcmp(a, b);
    char *c = (char *)malloc(lena + lenb + 1);
    strcpy(c, a);
    strcat(c, b);

    printf("strlen(A:%dB:%d)\n", lena, lenb);
    printf("strcmp(%d)\n", cmp);
    printf("strcat(%s)\n", c);

    free(c);
    return 0;
}
