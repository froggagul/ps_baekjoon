#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool broken[10] = { 0 };

int possible(int question) {
	if (question == 0) {
		if (broken[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while (question > 0) {
		if (broken[question % 10]) {
			return 0;
		}
		len += 1;
		question /= 10;
	}
	return len;
}

int main() {
	int question, answer;
	cin >> question;
	int n;
	cin >> n;
	while (n--) {
		int temp;
		cin >> temp;
		broken[temp] = true;
	}
	if (question - 100 > 0) {
		answer = question - 100;
	}
	else {
		answer = 100 - question;
	}
	for (int i = 0; i <= 1000000; i++) {
		int c = i;
		int len = possible(c);
		if (len > 0) {
			int press = c - question;
			if (press < 0) {
				press = -press;
			}
			if (answer > len + press) {
				answer = len + press;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}