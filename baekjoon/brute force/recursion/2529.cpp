#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

char relationship[10];
int temp[10];
int minNum[10];
bool isInitial = true;
int maxNum[10];
bool check[10];

void minGo(int index, int n) {
	if (index == n) {
		if (isInitial) {
			for (int i = 0; i < n; i++) {
				minNum[i] = temp[i];
			}
			isInitial = false;
		}
		return;
	}

	if (index > 0) {
		if (relationship[index - 1] == '<') {
			for (int i = temp[index - 1]; i <= 9; i++) {
				if (check[i]) continue;
				check[i] = true;
				temp[index] = i;
				minGo(index + 1, n);
				check[i] = false;
			}
		}
		else {
			for (int i = 0; i <= temp[index - 1]; i++) {
				if (check[i]) continue;
				check[i] = true;
				temp[index] = i;
				minGo(index + 1, n);
				check[i] = false;
			}
		}
		return;
	}
	else {
		for (int i = 0; i <= 9; i++) {
			if (check[i]) continue;
			check[i] = true;
			temp[index] = i;
			minGo(index + 1, n);
			check[i] = false;
		}
		return;
	}
}

void maxGo(int index, int n) {
	if (index == n) {
		if (isInitial) {
			for (int i = 0; i < n; i++) {
				maxNum[i] = temp[i];
			}
			isInitial = false;
		}
		return;
	}

	if (index > 0) {
		if (relationship[index - 1] == '<') {
			for (int i = 9; i >= temp[index - 1]; i--) {
				if (check[i]) continue;
				check[i] = true;
				temp[index] = i;
				maxGo(index + 1, n);
				check[i] = false;
			}
		}
		else {
			for (int i = temp[index - 1]; i >= 0; i--) {
				if (check[i]) continue;
				check[i] = true;
				temp[index] = i;
				maxGo(index + 1, n);
				check[i] = false;
			}
		}
		return;
	}
	else {
		for (int i = 9; i >= 0; i--) {
			if (check[i]) continue;
			check[i] = true;
			temp[index] = i;
			maxGo(index + 1, n);
			check[i] = false;
		}
		return;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> relationship[i];
	}
	n += 1;
	maxGo(0, n);
	for (int i = 0; i < n; i++) {
		cout << maxNum[i];
	}
	cout << '\n';
	isInitial = true;
	minGo(0, n);
	for (int i = 0; i < n; i++) {
		cout << minNum[i];
	}
	cout << '\n';
	return 0;
}