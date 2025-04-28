#include <stdio.h>

typedef char String[20];

int main(void)
{
    String sName = "aiueokakikukekosasisuseso";
    printf("%s\n", sName); // 20文字以上になると文字化けしそのあとが表示されない
    return 0;
}