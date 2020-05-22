#include <iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int n;
bool isLand[101][101];
int level[101][101];
int type[101][101];
queue<pair<int, int>> q;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int initx, int inity, char color) {
	type[initx][inity] = color;
	q.push({ initx, inity });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (!level[nx][ny] && isLand[nx][ny]) {
					level[nx][ny] = 1;
					type[nx][ny] = type[x][y];
					q.push({ nx, ny });
				}
			}
		}
	}
	return;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> isLand[i][j];
		}
	}
	char color = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!level[i][j] && isLand[i][j]) {
				bfs(i, j, color);
				color += 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (isLand[i][j]) {
				q.push({ i, j });
				level[i][j] = 1;
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
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (type[nx][ny] != type[x][y]) {
					if (level[nx][ny] == 0) {//아직 확장되지 않은 지역
						level[nx][ny] = level[x][y] + 1;
						type[nx][ny] = type[x][y];
						q.push({ nx, ny });
					}
				}
				// type이 같은 지역이면 넘어간다.
			}
		}
	}
	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (0 <= x && x < n && 0 <= y && y < n) {
					if (type[i][j] != type[x][y]) {
						if (ans == -1 || ans > level[i][j] + level[x][y]) {
							ans = level[i][j] + level[x][y];
						}
					}
				}
			}
		}
	}
	cout << ans - 2 << '\n';
	return 0;
}
