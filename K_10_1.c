#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char String[1024];

// 重複チェックと配列に値を入れる関数
void fillRandNums(int *arry, int length, int min, int max)
{
    int dupnum;    // 乱数入れる用
    int Muzui = 0; // dowhile文にて重複チェック用
    srand((unsigned)time(NULL));
    for (int i = 0; i < length; i++)
    {
        do
        {
            Muzui = 0;
            dupnum = (rand() % (max - min + 1)) + min;
            for (int t = 0; t < i; t++)
            {
                if (arry[t] == dupnum)
                {
                    Muzui = 1;
                }
            }
        } while (Muzui);

        *(arry + i) = dupnum; // 配列に値を入れる
    }
}

int main(void)
{
    int arry[11];
    int length = sizeof(arry) / sizeof(arry[0]);
    fillRandNums(arry, length, -5, 5);
    for (int n = 0; n < length; n++)
    {
        printf("%d,", arry[n]);
    }
    printf("\n");

    return 0;
}