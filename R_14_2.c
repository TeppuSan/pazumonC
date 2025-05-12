#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 自力では無理と判断

int main()
{
    FILE *fp;

    char header[54] = {};   // 管理情報の格納
    char image[97200] = {}; // 画像データの格納(3*W8*H8)

    // 管理情報を作成
    header[0] = 66;
    header[1] = 77;

    int *di;
    di = (int *)(header + 2); // ファイルサイズ
    *di = 97254;
    di = (int *)(header + 10);
    *di = 54;
    di = (int *)(header + 14); //
    *di = 40;
    di = (int *)(header + 18); // 横幅ピクセル数
    *di = 180;
    di = (int *)(header + 22); // 立幅ピクセル数
    *di = 180;

    short *ds;
    ds = (short *)(header + 26);
    *ds = 1;
    ds = (short *)(header + 28);
    *ds = 24;

    // 画像データを作成
    for (int i = 0; i < 97200; i += 3)
    {
        // RGBカラー
        image[i] = 253;    // 青
        image[i + 1] = 90; // 緑
        image[i + 2] = 20; // 赤
        /* code */
    }

    if ((fp = fopen("bluebox.bmp", "wb")) == NULL)
    {
        exit(1);
        /* code */
    }

    // データ書き込み
    fwrite(header, 54, 1, fp);   // 管理情報
    fwrite(image, 97200, 1, fp); // 画像データ

    fclose(fp);
    return 0;
}