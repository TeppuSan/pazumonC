#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sub.c"
#include "R_13_3.h"

int main()
{
    int max = 3;
    int num = createRand(max);
    char *Msg = selectMsg(num);
    printf("%s", Msg);
    return 0;
}
