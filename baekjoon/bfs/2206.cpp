#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dist[1000][1000][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<string> map(n);
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	queue<pair<pair<int, int>, int>> q;
	
	q.push({ {0, 0}, 0 });
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int isBroken = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (map[nx][ny] == '0' && dist[nx][ny][isBroken] == 0) {
					dist[nx][ny][isBroken] = dist[x][y][isBroken] + 1;
					q.push({ { nx, ny }, isBroken });
				}
				if (isBroken == 0 && map[nx][ny] == '1' && dist[nx][ny][!isBroken] == 0) {
					dist[nx][ny][isBroken + 1] = dist[x][y][isBroken] + 1;
					q.push({ { nx, ny }, isBroken + 1 });
				}
			}
		}
	}
	if (dist[n - 1][m - 1][0] != 0 && dist[n - 1][m - 1][1] != 0) {
		cout << min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
	}
	else if (dist[n - 1][m - 1][0] != 0) {
		cout << dist[n - 1][m - 1][0];
	}
	else if (dist[n - 1][m - 1][1] != 0) {
		cout << dist[n - 1][m - 1][1];
	}
	else {
		cout << -1;
	}
	cout << '\n';
	return 0;
}