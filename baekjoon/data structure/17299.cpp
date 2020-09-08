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
	vector<int> count(1000000);
	vector<int> answer(num);
	for (int i = 0; i < num; i++) {
		int curr;
		cin >> curr;
		question[i] = curr;
		count[curr - 1] += 1;
	}
	for (int i = 0; i < num; i++) {
		while (!s.empty() && count[question[s.top()] - 1] < count[question[i] - 1]) {
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