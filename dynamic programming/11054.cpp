#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int q[1001] = { 0 };
int desc[1001] = { 0 }; // desc[i]: q[i]로 시작하는 제일 긴 감소순열
int asc[1001] = { 0 }; // asc[i]: q[i]로 끝나는 제일 긴 증가순열
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
		int descCount = 0;
		for (int j = i + 1; j <= n; j++) {
			if (q[i] > q[j]) {
				if (descCount < desc[j]) {
					descCount = desc[j];
				}
			}
		}
		desc[i] = 1 + descCount;
	}
	for (int i = 1; i <= n; i++) {
		int ascCount = 0;
		for (int j = i; j >= 1; j--) {
			if (q[i] > q[j]) {
				if (ascCount < asc[j]) {
					ascCount = asc[j];
				}
			}
		}
		asc[i] = 1 + ascCount;
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < asc[i] + desc[i] - 1) {
			max = asc[i] + desc[i] - 1;
		}
	}
	cout << max << '\n';
	return 0;
}