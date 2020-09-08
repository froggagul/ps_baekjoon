#include<iostream>
#include<utility>
#include<queue>
using namespace std;

int a[300][300] = { 0 };
queue<pair<int, int>> q;
int dx[8] = { 1, 2, 1, 2, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -2, -1, -2, -1, 1, 2 };

int main() {
	int num;
	cin >> num;
	while (num--) {
		int n; //체스판 길이
		cin >> n;
		int initX, initY;
		cin >> initX >> initY;
		a[initX][initY] = 1;
		int lastX, lastY;
		cin >> lastX >> lastY;

		q.push({ initX, initY });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (a[nx][ny] == 0) {
						a[nx][ny] = a[x][y] + 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		cout << a[lastX][lastY] - 1 << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = 0;
			}
		}
	}
	return 0;
}