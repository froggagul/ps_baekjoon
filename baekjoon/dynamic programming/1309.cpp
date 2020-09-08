#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int d[100001] = { 0 };
int mod = 9901;
int main() {
	int num;
	cin >> num;
	d[0] = 1;
	d[1] = 2;
	for (int i = 2; i <= num; i++) {
		int temp = 0;
		for (int j = 0; j <= i - 2; j++) {
			temp += d[j] * 2;
		}
		temp += d[i - 1];
		d[i] = temp % mod;
	}
	int result = 0;
	for (int i = 0; i <= num; i++) {
		result += d[i];
	}
	cout << result % mod << '\n';
	return 0;
}