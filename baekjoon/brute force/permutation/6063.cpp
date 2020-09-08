#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int answer[10];	// 로또 번호
int numbers[10];

void go(int index, int n, int m, int prev) {
	if (m - index + 1 > n - prev) {
		return;
	}
	if (index == m + 1) {
		for (int i = 1; i <= m; i++) {
			cout << answer[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = prev + 1; i <= n; i++) {
		answer[index] = numbers[i];
		go(index + 1, n, m, i);
	}
}
int main() {
	for (;;) {
		int n;
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			cin >> numbers[i];
		}
		go(1, n, 6, 0);
		cout << '\n';
	}
	return 0;
}