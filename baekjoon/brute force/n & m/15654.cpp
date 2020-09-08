#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int numbers[10];
int answer[10];
int check[10];

void go(int index, int n, int m) {
	if (index == m + 1) {
		for (int i = 1; i <= m; i++) {
			cout << answer[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i]) continue;
		check[i] = true;
		answer[index] = numbers[i];
		go(index + 1, n, m);
		check[i] = false;
	}
}

int main() {
	int n;
	int m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
	}
	sort(numbers + 1, numbers + n + 1);
	go(1, n, m);
	return 0;
}