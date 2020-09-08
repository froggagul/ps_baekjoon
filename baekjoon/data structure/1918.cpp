#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stack>
using namespace std;

int checkOperator(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	else if (op == '(') {
		return 0;
	}
	return -1; //error;
}

int main() {
	stack<int> operators;
	string postfix;
	string infix;
	cin >> infix;
	for (int i = 0; i < infix.size(); i++) {
		char ch = infix[i];
		if (ch >= 'A' && ch <= 'Z') {
			postfix += ch;
		}
		else if (checkOperator(ch) > 0) {
			while (!operators.empty() && checkOperator(ch) <= checkOperator(operators.top())) {
				postfix += operators.top();
				operators.pop();
			}
			operators.push(ch);
		}
		else if (ch == '(') {
			operators.push(ch);
		}
		else if (ch == ')') {
			while (operators.top() != '(') {
				postfix += operators.top();
				operators.pop();
			}
			operators.pop(); // ( pop
		}
	}
	while (!operators.empty()) {
		postfix += operators.top();
		operators.pop();
	}
	cout << postfix << '\n';

	return 0;
}