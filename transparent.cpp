#include "transparent.h"

void my_putimage(int dstX, int dstY, IMAGE *pimg,
                 int avoid_color, int deviation,
                 double light, int tp)
{
    IMAGE* now_working = GetWorkingImage();

    IMAGE tempimg;
    Resize(&tempimg, pimg->getwidth(), pimg->getheight());

    SetWorkingImage(pimg);
    getimage(&tempimg, 0, 0, pimg->getwidth(), pimg->getheight());

    SetWorkingImage(now_working);

    IMAGE pSrcImg;
    getimage(&pSrcImg, dstX, dstY, pimg->getwidth(), pimg->getheight());

    if (tp < 0) tp = 0;
    if (tp > 100) tp = 100;

    DWORD* bk_pMem = GetImageBuffer(&pSrcImg);
    DWORD* pMem = GetImageBuffer(&tempimg);

    int avoid_r = GetRValue(avoid_color);
    int avoid_g = GetGValue(avoid_color);
    int avoid_b = GetBValue(avoid_color);

    for (int y = 0; y < pimg->getheight(); y++)
    {
        for (int x = 0; x < pimg->getwidth(); x++)
        {
            int num = y * pimg->getwidth() + x;
            int R = GetRValue(pMem[num]);
            int G = GetGValue(pMem[num]);
            int B = GetBValue(pMem[num]);

            if (abs(R - avoid_r) <= deviation &&
                abs(G - avoid_g) <= deviation &&
                abs(B - avoid_b) <= deviation)
            {
                pMem[num] = bk_pMem[num];
            }
            else
            {
                if (light > 0 && light < 1)
                {
                    R = int(R * light);
                    G = int(G * light);
                    B = int(B * light);
                }
                else if (light > 1)
                {
                    R = min(int(R * light), 255);
                    G = min(int(G * light), 255);
                    B = min(int(B * light), 255);
                }

                pMem[num] = RGB(
                    (R * tp + GetRValue(bk_pMem[num]) * (100 - tp)) / 100,
                    (G * tp + GetGValue(bk_pMem[num]) * (100 - tp)) / 100,
                    (B * tp + GetBValue(bk_pMem[num]) * (100 - tp)) / 100
                );
            }
        }
    }

    putimage(dstX, dstY, &tempimg);
}
