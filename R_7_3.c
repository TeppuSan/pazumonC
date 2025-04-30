#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct
{
    int code;
    char character;
    /* data */
} Ascii;

int main()
{
    Ascii characters[26] = {};
    int n = 0;
    for (int i = 65; i <= 90; i++)
    {
        characters[n].code = i;
        characters[n].character = (char)characters[n].code;
        printf("code%d character%c\n", characters[n].code, characters[n].character);
        n++;
    }

    return 0;
}
