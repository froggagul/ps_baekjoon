#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int q[1001] = { 0 };
int d[1001] = { 0 };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		q[i] = temp;
	}
	for (int i = n; i >= 1; i--) {
		int desc = 0;
		for (int j = i + 1; j <= n; j++) {
			if (q[i] > q[j]) {
				if (desc < d[j]) {
					desc = d[j];
				}
			}
		}
		d[i] = 1 + desc;
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < d[i]) {
			max = d[i];
		}
	}
	cout << max << '\n';
	return 0;
}