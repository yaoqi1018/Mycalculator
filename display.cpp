#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include "display.h"
using namespace std;

void showscreen()
{
    BeginBatchDraw();

    setfillcolor(RGB(0, 0, 0));
    solidrectangle(0, 0, WIN_W, WIN_H);

    settextcolor(WHITE);
    settextstyle(25, 0, _T("Consolas"));
    outtextxy(150, 10, _T("Calculator"));

    settextstyle(20, 0, _T("Consolas"));
    RECT rExpr = { 10, 100, 390, 160 };
    drawtext(formula.c_str(), &rExpr,
             DT_RIGHT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);

    settextstyle(60, 0, _T("Consolas"));
    RECT rResult = { 10, 200, 390, 320 };
    if (!expr.empty())
        drawtext(expr.c_str(), &rResult,
                 DT_RIGHT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    else if (!res.empty())
        drawtext(res.c_str(), &rResult,
                 DT_RIGHT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    else
        drawtext(_T("0"), &rResult,
                 DT_RIGHT | DT_VCENTER | DT_SINGLELINE);

    for (int i = 0; i < BTN_COLS; i++)
    {
        for (int j = 0; j < BTN_ROWS; j++)
        {
            int bx = BTN_START_X + i * (BTN_W + BTN_GAP);
            int by = BTN_START_Y + j * (BTN_H + BTN_GAP);
            char c = btnChar[i][j];

            COLORREF bgColor;
            if (c == 'C' || c == 'D')
                bgColor = RGB(200, 40, 40);
            else if (c == '=')
                bgColor = RGB(0, 160, 0);
            else if (c == '+' || c == '-' || c == '*' || c == '/')
                bgColor = RGB(30, 120, 200);
            else
                bgColor = RGB(60, 60, 60);

            setfillcolor(bgColor);
            solidrectangle(bx, by, bx + BTN_W, by + BTN_H);

            settextcolor(WHITE);
            settextstyle(30, 0, _T("Consolas"));
            tstring label;
            if (c == 'D') label = _T("Del");
            else { label += (TCHAR)c; }
            RECT rBtn = { bx, by, bx + BTN_W, by + BTN_H };
            drawtext(label.c_str(), &rBtn,
                     DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }

    EndBatchDraw();
}
