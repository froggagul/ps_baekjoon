#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int answers[10];
bool checks[10];

void go(int index, int n) {
	if (index == n) {
		for (int i = 0; i < n; i++) {
			cout << answers[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (checks[i]) continue;
		checks[i] = true;
		answers[index] = i;
		go(index + 1, n);
		checks[i] = false;
	}
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		checks[i] = false;
	}
	go(0, n);
	return 0;
}