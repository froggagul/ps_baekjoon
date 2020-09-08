#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int map[8][8] = { 0 };
queue<pair<int, int>> q;

int n, m;

int bfs() {
	int copy[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy[i][j] = map[i][j];
			if (copy[i][j] == 2) {
				q.push({ i, j });
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (copy[nx][ny] == 0) {
					copy[nx][ny] = 2;
					q.push({ nx, ny });
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copy[i][j] == 0) {
				cnt += 1;
			}
		}
	}
	return cnt;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) {
			if (map[x1][y1] != 0) continue;
			for (int x2 = 0; x2 < n; x2++) {
				for (int y2 = 0; y2 < m; y2++) {
					if (map[x2][y2] != 0) continue;
					for (int x3 = 0; x3 < n; x3++) {
						for (int y3 = 0; y3 < m; y3++) {
							if (map[x3][y3] != 0) continue;
							if (x1 == x2 && y1 == y2) continue;
							if (x1 == x3 && y1 == y3) continue;
							if (x2 == x3 && y2 == y3) continue;
							map[x1][y1] = 1;
							map[x2][y2] = 1;
							map[x3][y3] = 1;
							int cur = bfs();
							if (ans < cur) ans = cur;
							map[x1][y1] = 0;
							map[x2][y2] = 0;
							map[x3][y3] = 0;
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}