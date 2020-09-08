#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
long long d[201][201] = { 0 };

int main() {
	int num;
	int k;
	cin >> num;
	cin >> k;
	long long mod = 1000000000;
	for (int i = 0; i <= num; i++) {
		for (int j = 1; j <= k; j++) {
			if (j == 1 || i == 0) {
				d[i][j] = 1;
			}
			else {
				for (int prev = 0; prev <= i; prev++) {
					d[i][j] = (d[i][j] + d[prev][j - 1]) % mod;
				}
			}
		}
	}
	cout << d[num][k] % mod << '\n';
	return 0;
}
// 중복조합으로 바로 풀리기도 함