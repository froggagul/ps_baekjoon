#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int main() {
	int num;
	cin >> num;
	stack<int> s;
	vector<int> question(num);
	vector<int> answer(num);	//c++의 vector 자료형
	for (int i = 0; i < num; i++) {
		cin >> question[i];
	}
	for (int i = 0; i < num; i++) {
		while (!s.empty() && question[s.top()] < question[i]) {
			answer[s.top()] = question[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < num; i++) {
		cout << (answer[i] == 0 ? -1 : answer[i]) << ' ';
	}
	return 0;
}