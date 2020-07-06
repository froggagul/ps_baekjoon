#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string map[101];
bool visit[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
struct node {
	int x, y;
};
void bfs(int n, node start) {
	queue<node> q;
	q.push(start);
	visit[start.x][start.y] = true;
	char type = map[start.x][start.y];
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (!visit[nx][ny]) {
				if (map[nx][ny] == type) {
					visit[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				bfs(n, { i, j });
				ans += 1;
			}
		}
	}
	cout << ans << " ";
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				bfs(n, { i, j });
				ans += 1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}