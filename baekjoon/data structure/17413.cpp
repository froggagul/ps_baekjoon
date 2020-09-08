#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(nullptr);
	string question;
	stack<char> s;
	bool isTag = false;
	getline(cin, question);
	for (char ch: question) {
		if (ch == '<' || ch == ' ') {//모든 문자는 <아니면 space bar로 구분된다.
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			if (ch == '<') {
				isTag = true;
			}
			cout << ch;
		}
		else if (ch == '>') {
			isTag = false;
			cout << ch;
		}
		else {
			if (isTag) {
				cout << ch;
			}
			else {
				s.push(ch);
			}
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}