#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef char String[1024];

int main()
{
    printf("いただきます\nバナナを食べます\n");
    bool more = false;
    if (more)
        printf("お代わりをください\n");
    else
        printf("おなかいっぱいです\n");
    printf("ごちそうさまでした\n");
}