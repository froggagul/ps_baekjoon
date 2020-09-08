#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int d[1001][3] = { 0 };
int q[1001][3] = { 0 };

int main() {
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		for (int j = 0; j < 3; j++) {
			int curr;
			cin >> curr;
			q[i][j] = curr;
		}
	}
	for (int i = num; i >= 1; i--) {
		if (i == num) {
			for (int j = 0; j < 3; j++) {
				d[i][j] = q[i][j];
			}
		}
		else {
			for (int j = 0; j < 3; j++) {
				int case1 = q[i][j] + d[i + 1][(j + 1) % 3];
				int case2 = q[i][j] + d[i + 1][(j + 2) % 3];
				d[i][j] = case1 > case2 ? case2 : case1;
			}
		}
	}
	int min = d[1][0];
	for (int i = 1; i < 3; i++) {
		if (min > d[1][i]) {
			min = d[1][i];
		}
	}
	cout << min << '\n';
	return 0;
}