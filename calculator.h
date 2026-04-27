#pragma once
#include <easyx.h>
#include <string>
#ifdef UNICODE
    typedef std::wstring tstring;
#else
    typedef std::string tstring;
#endif

    extern tstring expr;
    extern tstring formula;
    extern tstring res;
    extern bool button[4][5];

    extern const int WIN_W;    // 窗口宽度
    extern const int WIN_H;    // 窗口高度
    extern const int BTN_COLS; // 按钮列数
    extern const int BTN_ROWS; // 按钮行数
    extern const int BTN_W;    // 按钮宽度
    extern const int BTN_H;    // 按钮高度
    extern const int BTN_GAP;  // 按钮间距
    extern const int BTN_START_X; // 按钮起始X
    extern const int BTN_START_Y; // 按钮起始Y
    extern const char btnChar[4][5];

    void Digit(char c);
    void Operator(char op);
    void leftParen();
    void rightParen();
    void Equal();
    void Clear();
    void Delete();

    void updatewithinput();    // 处理鼠标输入
    void showscreen();         // 绘制界面

