#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(nullptr);
	string question;
	int iron = 0;
	int stackLength = 0;
	int laser = 0;
	getline(cin, question);
	for (char ch: question) {
		if (ch == '(') {
			iron += 1;
			stackLength += 1;
			laser = 1;
		}
		else if (ch == ')') {
			if (laser == 1) { // laser인 경우, stack을 사용하면 stack.top()과 현재 index의 차이가 1이면 laser로 판단.
				iron -= 1;
				stackLength -= 1; // 철인줄 알았는데!
				iron += stackLength;
				laser = 0;
			}
			else { //laser가 아닌 철막대의 끝인 경우
				stackLength -= 1;
			}
		}
	}
	cout << iron;
	return 0;
}