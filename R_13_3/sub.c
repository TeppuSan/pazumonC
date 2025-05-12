#include <stdlib.h>
#include <time.h>
#include "R_13_3.h"

int createRand(int max)
{
    srand((unsigned)time(NULL));
    return (rand() % max + 1);
}

char *selectMsg(int num)
{
    char *rem;
    switch (num)
    {
    case 1:
        rem = "When you give up, that's when the game is over.\n";
        /* code */
        break;
    case 2:
        rem = "He stole something quite precious...your heart.\n";
        /* code */
        break;
    case 3:
        rem = "There's only one truth!.\n";
        /* code */
        break;
    }
    return rem;
}
