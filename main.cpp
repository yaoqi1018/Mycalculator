#include <windows.h>
#include "easyx.h"
#include "calculator.h"
#include "display.h"
#include "input.h"
#include "calc.h"

int main() {
    initgraph(400, 600);
    SetWindowText(GetHWnd(), _T("Calculator"));

    while (true) {
        updatewithinput();
        showscreen();
        Sleep(20);
    }

    closegraph();
    return 0;
}
