#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int q[10001] = { 0 };
int d[10001] = { 0 }; //d[i] : i번째 와인까지 주어졌을때, 먹을 수 있는 와인의 최대값

int max(int a, int b, int c) {
	if (a > b) {
		if (c > a) {
			return c;
		}
		else {
			return a;
		}
	}
	else {
		if (c > b) {
			return c;
		}
		else {
			return b;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		q[i] = temp;
	}
	d[1] = q[1];
	d[2] = q[1] + q[2];
	for (int i = 3; i <= n; i++) {
		int case1 = d[i - 1];
		int case2 = d[i - 2] + q[i];
		int case3 = d[i - 3] + q[i] + q[i - 1];
		d[i] = max(case1, case2, case3);
	}
	cout << d[n] << '\n';
	return 0;
}