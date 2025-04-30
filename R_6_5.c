#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef char String[1024];

typedef struct
{
    String title;
    String from;
    String datetime;
    int size;
    bool attached;
    String body;
    /* data */
} Mail;

Mail m = {"あけましておめでとう",
          "sugawara@miyabilink.jp",
          "2025/01/01 10:10:58",
          302,
          false};

int main(int argc, char const *argv[])
{
    printf("メール受信のお知らせ\n");
    printf("%sさんから、%sにメールです。サイズは%dKB、%d。\n", m.from, m.datetime, m.size, m.attached);
    /* code */
    return 0;
}
