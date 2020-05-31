#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int R, C;
char a[21][21] = { 0 };
bool a_check[20][20] = { 0 };
bool check[26] = { 0 };
int ans = 0;
int dR[4] = { 0, 0, -1, 1 };
int dC[4] = { 1, -1, 0, 0 };

void go(int row, int col, int cnt) {
	bool isEnd = true;
	check[a[row][col] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int nR = row + dR[i];
		int nC = col + dC[i];
		if (nR >= 0 && nR < R && nC >= 0 && nC < C) {
			int curr = a[nR][nC] - 'A';
			if (!check[curr]) {
				go(nR, nC, cnt + 1);
				isEnd = false;
			}
		}
	}
	check[a[row][col] - 'A'] = false;
	if (isEnd) {
		if (cnt > ans) {
			ans = cnt;
		}
	}
	return;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> a[i];
	}
	go(0, 0, 1);
	cout << ans << '\n';
}