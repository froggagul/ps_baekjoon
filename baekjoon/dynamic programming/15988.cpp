#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
long long d[1000001][4] = { 0 };
const long long mod = 1000000009LL;

int main() {
	int num;
	cin >> num;
	for (int i = 1; i < 1000001; i++) {
		for (int j = 1; j < 4; j++) {
			if (i == j) {
				d[i][j] = 1;
			}
			else {
				if (i - j >= 1) {
					d[i][j] += d[i - j][1];
				}
				if (i - j >= 2) {
					d[i][j] += d[i - j][2];
				}
				if (i - j >= 3) {
					d[i][j] += d[i - j][3];
				}
				d[i][j] %= mod;
			}
		}
	}
	while (num--) {
		int curr;
		cin >> curr;
		cout << (d[curr][1] + d[curr][2] + d[curr][3]) % mod << '\n';
	}
	return 0;
}