#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int ability[20][20] = { 0 };
int start[10] = { 0 };
int link[10] = { 0 };

int check(int n) {
	n /= 2;
	int startSum = 0;
	int linkSum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			startSum += ability[start[i]][start[j]] + ability[start[j]][start[i]];
			linkSum += ability[link[i]][link[j]] + ability[link[j]][link[i]];
		}
	}
	if (startSum > linkSum) {
		return startSum - linkSum;
	}
	else {
		return linkSum - startSum;
	}
}

int go(int index, int startSize, int linkSize, int n) {
	if (startSize > n / 2 || linkSize > n / 2) return -1;
	if (index == n) {
		return check(n);
	}
	start[startSize] = index;
	int first = go(index + 1, startSize + 1, linkSize, n);
	start[startSize] = 0;
	link[linkSize] = index;
	int second = go(index + 1, startSize, linkSize + 1, n);
	link[linkSize] = 0;
	if (second == -1) return first;
	if (first == -1 || first > second) return second;
	return first;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ability[i][j];
		}
	}
	int sum = go(0, 0, 0, n);
	cout << sum << '\n';
	return 0;
}