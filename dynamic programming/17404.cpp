#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int d[1001][9] = { 0 };
int q[1001][3] = { 0 };
//d[i][j] = 총길이 n인집을 칠하는데, j는 각 집의 색깔을 3진법으로 나타낸 값이다.
/*
R, G, B는 각각 0, 1, 2를 나타내는데, BR는 20로 6을 나타낸다. 
*/

int min(int a, int b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return a < b ? a : b;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			int temp;
			cin >> temp;
			q[i][j] = temp;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (i == 2) {
			for (int j = 0; j <= 8; j++) {
				int first = j / 3;
				int last = j % 3;
				if (first != last) {
					d[i][j] = q[1][first] + q[2][last];
				}
			}
		}
		else {
			for (int j = 0; j <= 8; j++) {
				int first = j / 3;
				int last = j % 3;
				d[i][j] = q[i][last] + min(d[i - 1][first * 3 + (last + 1) % 3], d[i - 1][first * 3 + (last + 2) % 3]);
			}
		}
	}
	int result = 0;
	for (int i = 0; i <= 8; i++) {
		int first = i / 3;
		int last = i % 3;
		if (first != last) {
			result = min(result, d[n][i]);
		}
	}
	cout << result << '\n';
	return 0;
}