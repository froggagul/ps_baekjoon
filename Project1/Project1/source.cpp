#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
using namespace std;
int d[100001] = { 0 };
int q[100001] = { 0 };

int main() {
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		int temp;
		cin >> temp;
		d[i] = temp;
	}
	q[num] = d[num];
	for (int i = num - 1; i >= 1; i--) {
		q[i] = d[i];
		if (0 < q[i + 1]) {
			q[i] = d[i] + q[i + 1];
		}
	}
	int max = q[1];
	for (int i = 2; i <= num; i++) {
		if (max < q[i]) {
			max = q[i];
		}
	}
	cout << max << '\n';
	return 0;
}