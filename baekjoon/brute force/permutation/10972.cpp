#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int question[10002];
bool checks[10002];

void go(int index, int n) {
	if (index == n + 1) {
		for (int i = 1; i <= n; i++) {
			cout << question[i] << " ";
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (checks[i]) continue;
		checks[i] = true;
		question[index] = i;
		go(index + 1, n);
		break;
	}
	return;
}

void next(int index, int n) {
	for (int i = question[index] + 1; i <= n; i++) {
		if (checks[i]) continue;
		checks[i] = true;
		question[index] = i;
		go(index + 1, n);
		break;
	}
	return;
}

void back(int index, int n) {
	bool isEnd = false;
	for (int i = question[index] + 1; i <= n; i++) {
		if (checks[i]) continue;
		checks[question[index]] = false;
		isEnd = true;
		next(index, n);
		break;
	}
	if (!isEnd) {
		checks[question[index]] = false;
		if (index == 1) {
			cout << -1 << '\n';
			return;
		}
		else {
			question[index] = 0;
			back(index - 1, n);
			return;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> question[i];
		checks[i] = true;
	}
	back(n, n);
	return 0;
}