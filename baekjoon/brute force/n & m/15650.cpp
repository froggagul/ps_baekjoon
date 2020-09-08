#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int answer[10];
bool check[10] = {false};

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
		if (check[i]) continue;
		check[i] = true;
		answer[index] = i;
		go(index + 1, n, m, i);
		check[i] = false;
	}
}

int main() {
	int n;
	int m;
	cin >> n;
	cin >> m;
	go(1, n, m, 0);
	return 0;
}