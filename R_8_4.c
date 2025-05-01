#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef char String[1024];

int isCnaf()
{
    String inputStr;
    scanf("%s", inputStr);
    int inputint = atoi(inputStr);
    return inputint;
}

int calcPayment(int amout, int people)
{
    double dnum = (double)amout / people;
    int pay = (int)(dnum / 100) * 100;
    if (dnum > pay)
    {
        pay = pay + 100;
    }
    return pay;
}

void showPayment(int pay, int payorg, int people)
{
    printf("*** 支払額 ***\n");
    printf("1人あたり%d円(%d人)、幹事は%d円です。\n", pay, people, payorg);
}

int main()
{

    int amout;
    int people;
    int pay;
    int payorg;

    printf("支払総額を入力してください\n");
    amout = isCnaf();

    printf("参加人数を入力してください\n");
    people = isCnaf();

    pay = calcPayment(amout, people);

    payorg = amout - pay * (people - 1);

    showPayment(pay, payorg, people);

    return 0;
}