#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

bool isLipYear(int Year)
{
    bool hantei = false;

    if (Year % 400 == 0)
        hantei = true;
    if (Year % 4 == 0 && Year % 100 != 0)
        hantei = true;
    return hantei;
}

int main()
{
    int hantei = false;
    int Year = 2025;
    hantei = isLipYear(Year);
    if (hantei == true)
        printf("%d年は、うるう年です\n", Year);
    if (hantei == false)
        printf("%d年は、うるう年ではありません\n", Year);
}