#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("エラーです!\n");
        exit(1);
        /* code */
    }
    FILE *frb = fopen(argv[1], "rb");
    if (frb == NULL)
    {
        printf("ファイルが開けません!\n");
        exit(1);
        /* code */
    }
    FILE *fwb = fopen(argv[2], "wb");
    if (fwb == NULL)
    {
        printf("書き込みできません!\n");
        fclose(frb);
        exit(1);
        /* code */
    }
    int frbfp;

    while ((frbfp = fgetc(frb)) != EOF)
    {
        fputc(frbfp, fwb);
        /* code */
    }
    fclose(frb);
    fclose(fwb);
}