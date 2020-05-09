#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int numbers[10];
int answer[10];
bool checks[10];

void go(int index, int n, int m) {
	if (index == m + 1) {
		for (int i = 1; i <= m; i++) {
			cout << answer[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (numbers[i] == numbers[i - 1] && checks[i - 1] == false) continue;
		if (checks[i]) continue;
		checks[i] = true;
		answer[index] = numbers[i];
		go(index + 1, n, m);
		checks[i] = false;
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