#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int result = 0;
int answers[10];
int numbers[10];
bool checks[10];

int absolute(int a, int b) {
	int result = a - b;
	if (result > 0) return result;
	else return -result;
}


void go(int index, int n) {
	if (index == n) {
		int temp = 0;
		for (int i = 0; i < n - 1; i++) {
			temp += absolute(answers[i], answers[i + 1]);
			if (temp > result) result = temp;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (checks[i]) continue;
		checks[i] = true;
		answers[index] = numbers[i];
		go(index + 1, n);
		checks[i] = false;
	}
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
		checks[i] = false;
	}
	go(0, n);
	cout << result << '\n';
	return 0;
}