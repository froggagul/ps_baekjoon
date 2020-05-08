#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int q[100001] = { 0 };
int d[100001][2] = { 0 };
//d[n][0] : n번째에서 시작하는 연속합의 최댓값
//d[n][1] : 하나를 빼서 만들 수 있는 n부터 시작하는 연속합의 최댓값

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		q[i] = temp;
	}
	d[n][0] = q[n];
	d[n][1] = q[n];
	for (int i = n - 1; i >= 1; i--) {
		d[i][1] = max(d[i + 1][1] + q[i], d[i + 1][0]);
		d[i][0] = max(d[i + 1][0] + q[i], q[i]);
	}
	int result = d[n][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 1; j++) {
			result = max(result, d[i][j]);
		}
	}
	cout << result << '\n';
	return 0;
}