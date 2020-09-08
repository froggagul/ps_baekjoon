#include<iostream>
#include<utility>
#include<queue>
using namespace std;

int a[1000][1000] = { 0 };
bool check[1000][1000] = { 0 };
queue<pair<int, int>> q;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	int n, m; //너비, 높이
	cin >> n >> m;
	for (int i = 0; i < m; i++) {//높이
		for (int j = 0; j < n; j++) {//너비
			cin >> a[i][j];
			if (a[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int currX = x + dx[i];
			int currY = y + dy[i];
			if (currX >= 0 && currX < m && currY >= 0 && currY < n) {
				if (!check[currX][currY] && a[currX][currY] == 0) {
					check[currX][currY] = true;
					a[currX][currY] = a[x][y] + 1;
					q.push({ currX, currY });
				}
			}
		}
	}
	int maxCount = 0;
	for (int i = 0; i < m; i++) {//높이
		for (int j = 0; j < n; j++) {//너비
			if (a[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			if (maxCount < a[i][j]) {
				maxCount = a[i][j];
			}
		}
	}
	cout << maxCount - 1 << '\n';
	return 0;
}