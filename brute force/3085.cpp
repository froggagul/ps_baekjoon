#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int check(char (*arr)[50], size_t size) {
	int ans = 1;
	for (int i = 0; i < size; i++) {
		int cnt = 1;
		for (int j = 1; j < size; j++) {
			if (arr[i][j] == arr[i][j - 1]) {
				cnt += 1;
			}
			else {
				cnt = 1;
			}
			if (ans < cnt) ans = cnt;
		}
		cnt = 1;
		for (int j = 1; j < size; j++) {
			if (arr[j][i] == arr[j - 1][i]) {
				cnt += 1;
			}
			else {
				cnt = 1;
			}
			if (ans < cnt) ans = cnt;
		}
	}
	return ans;
}

int main() {
	char a[50][50] = { 0 };
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j + 1 < size) {
				swap(a[i][j], a[i][j + 1]);
				int temp = check(a, size);
				if (ans < temp) ans = temp;
				swap(a[i][j], a[i][j + 1]);
			}
			if (i + 1 < size) {
				swap(a[i][j], a[i + 1][j]);
				int temp = check(a, size);
				if (ans < temp) ans = temp;
				swap(a[i][j], a[i + 1][j]);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}