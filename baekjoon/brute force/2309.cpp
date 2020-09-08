#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int a[9] = { 0 };
int n = 9;

int main() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n); //a부터 a+9까지 sort
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sum - a[i] - a[j] == 100) {
				for (int k = 0; k < n; k++) {
					if (i == k || j == k) continue;
					cout << a[k] << '\n';
				}
				return 0;
			}
		}
	}
	return 0;
}