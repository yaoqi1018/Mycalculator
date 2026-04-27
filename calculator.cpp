#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <sstream>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;

//=====global variables=====

tstring expr;
tstring formula;
tstring res;

bool button[4][5] = { false };

const int WIN_W = 400;          // 窗口宽度
const int WIN_H = 600;          // 窗口高度
const int BTN_COLS = 4;         // 按钮有4列
const int BTN_ROWS = 5;         // 按钮有5行
const int BTN_W = 90;           // 每个按钮宽90像素
const int BTN_H = 50;           // 每个按钮高50像素
const int BTN_GAP = 6;          // 按钮之间间距6像素
const int BTN_START_X = 6;      // 第一个按钮的X坐标
const int BTN_START_Y = 340;    // 第一个按钮的Y坐标


const char btnChar[4][5] = {
    {'C', '7', '4', '1', '('},
    {'0', '8', '5', '2', '.'},
    {'D', '9', '6', '3', ')'},
    {'=', '*', '-', '+', '/'}
};