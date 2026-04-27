# Mycalc

基于 C++ 和 EasyX 图形库的桌面计算器。

## 功能

- 四则运算（加、减、乘、除）
- 括号支持
- 小数输入
- Del 退格 / C 清空

## 环境要求

- Visual Studio 2022（或 2019），需安装 **"使用 C++ 的桌面开发"** 工作负载
- [EasyX 图形库](https://easyx.cn) — 下载安装即可

## 运行方法

```bash
git clone https://github.com/yaoqi1018/Mycalculator.git
```

用 Visual Studio 打开 `Mycalc.sln`，选择 **x64** 平台，按 **F5** 运行。

## 项目结构

```
Mycalc/
├── main.cpp           # 程序入口
├── calculator.h/cpp   # 全局变量与常量定义
├── calc.h/cpp         # 计算逻辑（输入处理、表达式求值）
├── display.h/cpp      # 界面绘制
├── input.h/cpp        # 鼠标输入处理
├── loadimage.h/cpp    # 图片加载工具
└── transparent.h/cpp  # 透明贴图工具
```
