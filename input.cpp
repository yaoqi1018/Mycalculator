#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include "input.h"
#include "calc.h"
using namespace std;

void updatewithinput()
{
    ExMessage m;
    while (peekmessage(&m, EX_MOUSE))
    {
        for (int i = 0; i < BTN_COLS; i++)
        {
            for (int j = 0; j < BTN_ROWS; j++)
            {
                int bx = BTN_START_X + i * (BTN_W + BTN_GAP);
                int by = BTN_START_Y + j * (BTN_H + BTN_GAP);

                if (m.x >= bx && m.x <= bx + BTN_W &&
                    m.y >= by && m.y <= by + BTN_H)
                {
                    button[i][j] = true;
                    if (m.message == WM_LBUTTONDOWN)    // 左键按下
                    {
                        char c = btnChar[i][j];        // 获取按钮上的字符
                        switch (c)                     // 根据字符调用对应函数
                        {
                        case 'C':  Clear();      break;  // 清空
                        case 'D':  Delete();     break;  // 退格
                        case '=':  Equal();      break;  // 等号（还没实现）
                        case '(':  leftParen();  break;  // 左括号
                        case ')':  rightParen(); break;  // 右括号
                        case '.':  Digit('.');    break;  // 小数点
                        case '+':  Operator('+'); break;  // 加
                        case '-':  Operator('-'); break;  // 减
                        case '*':  Operator('*'); break;  // 乘
                        case '/':  Operator('/'); break;  // 除
                        default:
                            if (c >= '0' && c <= '9')
                                Digit(c);               // 数字
                            break;
                        }
                    }
                }
                else
                {
                    button[i][j] = false;
                }
            }
        }
    }
}
