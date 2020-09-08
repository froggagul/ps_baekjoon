#include <iostream>
#include<stack>
using namespace std;

char a[51][51] = { 0 };
bool check[51][51] = { 0 }; //0: 방문 X  1: 방문 O
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m;

bool go(int x, int y, int px, int py, char color) {
	if (check[x][y]) return true;
	check[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (!(nx == px && ny == py) && a[nx][ny] == color) {
				if (go(nx, ny, x, y, color)) return true;
			}
		}
	}
	return false;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j]) continue;
			if (go(i, j, i, j, a[i][j])) {
				cout << "Yes" << '\n';
				return 0;
			}
		}
	}
	cout << "No" << '\n';
	return 0;
}