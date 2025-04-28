#include <stdio.h>

typedef char String[1024];

int main(void)
{
    String color = "グリーン";
    String Name = "スライム";
    printf("%s", color + Name); // グリーンスライムにしたくて…
    return 0;
}