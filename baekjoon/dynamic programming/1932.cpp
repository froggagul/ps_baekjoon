#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
const int MAX = 501 * 500 / 2 + 1;
using namespace std;
int q[MAX] = { 0 };
int d[MAX] = { 0 };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n * (n + 1) / 2; i++) {
		int temp;
		cin >> temp;
		q[i] = temp;
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			int index = i * (i - 1) / 2 + j;
			if (i == n) {
				d[index] = q[index];
			}
			else {
				int topIndex = i * (i + 1) / 2 + j;
				d[index] = d[topIndex] > d[topIndex + 1] ? d[topIndex] + q[index] : d[topIndex + 1] + q[index];
			}
		}
	}
	cout << d[1] << '\n';
	return 0;
}