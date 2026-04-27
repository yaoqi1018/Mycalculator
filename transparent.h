#pragma once
#include <easyx.h>

void my_putimage(int dstX, int dstY, IMAGE *pimg,
                 int avoid_color, int deviation,
                 double light, int tp);
