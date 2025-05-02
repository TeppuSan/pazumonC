#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char String[1024];

int main(int argc, char const *argv[])
{
    char *memori = (char *)malloc(13);
    strcpy(memori, "misaki");
    strcpy(memori + 7, "akagi");
    char *names[2];
    names[0] = memori;
    names[1] = memori + 7;
    for (int i = 0; i < 2; i++)
    {
        printf("%s名前\n", names[i]);
    }

    free(memori);
    return 0;
}
