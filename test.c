#include <stdio.h>

int main(void)
{
    int color = 3;
    printf("\x1b[3%dm]aaa", color);
}