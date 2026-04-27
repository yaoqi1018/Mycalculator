#include "calculator.h"
#include <stack>

void Digit(char c) {
	if ((int)expr.length() >= 18) return;
	if (c == '.') {
		if (expr.find('.') == tstring::npos)
			expr += (TCHAR)c;
	} else {
		expr += (TCHAR)c;
	}
}

void Operator(char op) {
	if (!expr.empty()) {
		formula += expr;
		expr.clear();
	}
	formula += (TCHAR)op;
}

void leftParen() {
	if (!expr.empty()) {
		formula += expr;
		expr.clear();
	}
	formula += (TCHAR)'(';
}

void rightParen() {
	if (!expr.empty()) {
		formula += expr;
		expr.clear();
	}
	formula += (TCHAR)')';
}


void Clear() {
	expr.clear();
	formula.clear();
	res.clear();
}

void Delete() {
	if (!expr.empty()) {
		expr.pop_back();
	}
	else if (!formula.empty()) {
		formula.pop_back();
	}
}
int priority(char ch) {
	if (ch == '+' || ch == '-')return 1;
	else if (ch == '*' || ch == '/')return 2;
	else return 0;
}
void Equal() {
	tstring full = formula + expr;

	if (full.empty()) {
		res = _T("Empty input!");
		formula.clear();
		expr.clear();
		return;
	}

	std::stack<char> ops;
	tstring newformula;
	for (int i = 0; i < full.length(); ++i) {
		TCHAR ch = full[i];
		
		//数字
		if ((ch >= '0' && ch <= '9')||ch=='.') {
			while (i + 1 < full.length() && ((full[i+1] >= '0' && full[i+1] <= '9') || full[i+1] == '.')) {
				newformula += full[i];
				i++;
			}
			newformula += full[i];
			newformula += ' ';
		}
		//左括号
		else if (ch == '(') {
			ops.push('(');
		}
		//右括号
		else if (ch == ')') {

			while (!ops.empty() && ops.top() != '(') {
				newformula += ops.top();
				ops.pop();
				newformula += ' ';
			}
			if (ops.empty()) {
				res = _T("Parentheses error!");
				formula.clear();
				expr.clear();
				return;
			}
			else ops.pop();
		}

		else {
			while (!ops.empty() && priority(ops.top()) >= priority(ch)) {
				newformula += ops.top();
				newformula += ' ';
				ops.pop();
			}
			ops.push(ch);
		}
	}

	while (!ops.empty()) {
		newformula += ops.top();
		newformula += ' ';
		ops.pop();
	}

	std::stack<double>nums;
	for (int i = 0; i < newformula.length(); ++i) {
		if (newformula[i] >= '0' && newformula[i] <= '9') {
			tstring numstr;
			while (i < newformula.length()&&(newformula[i] >= '0' && newformula[i] <= '9' ||newformula[i] == '.')) {
				numstr += newformula[i];
				i++;
			}
			i--;
			double num = _wtof(numstr.c_str());
			nums.push(num);
		}
		else if (newformula[i] == ' ')continue;
		else {
			//检查 一个符号至少有两个数
			if (nums.size() < 2) {
				res = _T("Invalid expression");
				formula.clear();
				expr.clear();
				return;
			}

			if (newformula[i] =='+') {
				double x1 = nums.top();
				nums.pop();
				double x2 = nums.top();
				double x3 = x1 + x2;
				nums.push(x3);
			}

			else if (newformula[i] == '*') {
				double x1 = nums.top();
				nums.pop();
				double x2 = nums.top();
				double x3 = x1 * x2;
				nums.push(x3);
			}
			
			else if (newformula[i] == '-') {
				double x1 = nums.top();
				nums.pop();
				double x2 = nums.top();
				double x3 = x2-x1;
				nums.push(x3);
			}
			
			else if (newformula[i] == '/') {
				double x1 = nums.top();

				if (x1 == 0) {
					res = _T("Divisor error!");
					formula.clear();
					expr.clear();
					return;
				}

				nums.pop();
				double x2 = nums.top();
				double x3 = x2 / x1;
				nums.push(x3);
			}
		}
	}
	
	double result = nums.top();
	res = std::to_wstring(result);
	formula.clear();
	expr =res;
}
