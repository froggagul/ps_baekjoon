#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int answer[10];

void go(int index, int n, int m) {
	if (index == m + 1) {
		for (int i = 1; i <= m; i++) {
			cout << answer[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		answer[index] = i;
		go(index + 1, n, m);
	}
}

int main() {
	int n;
	int m;
	cin >> n;
	cin >> m;
	go(1, n, m);
	return 0;
}