#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int map[50][50];
int goal[50][50];
void change(int x, int y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			map[x + i][y + j] = map[x + i][y + j] == 1 ? 0 : 1;
		}
	}
	return;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &goal[i][j]);
		}
	}
	if (n < 3 || m < 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != goal[i][j]) {
					cout << -1 << '\n';
					return 0;
				}
			}
		}
		cout << 0 << '\n';
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			if (map[i][j] != goal[i][j]) {
				change(i, j);
				cnt += 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != goal[i][j]) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}