#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int d[1001][10] = { 0 }; //d[i][j] : i자리 수의 오름차수 중 첫 자리가 j인 수들의 가짓수
int mod = 10007;
int main() {
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		if (i == 1) {
			for (int j = 0; j < 10; j++) {
				d[i][j] = 1;
			}
		}
		else {
			for (int j = 0; j < 10; j++) {
				int temp = 0;
				for (int k = j; k < 10; k++) {
					temp += d[i - 1][k];
				}
				d[i][j] = temp % mod;
			}
		}
	}
	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += d[num][i];
	}
	cout << result % mod << '\n';
	return 0;
}