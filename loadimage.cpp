#include "loadimage.h"

IMAGE setimage(int width, int height, COLORREF rgb)
{
    IMAGE img(width, height);
    SetWorkingImage(&img);
    setfillcolor(rgb);
    solidrectangle(0, 0, width, height);
    SetWorkingImage();
    return img;
}
