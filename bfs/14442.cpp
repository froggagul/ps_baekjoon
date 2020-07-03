#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
string map[1000];
bool visit[11][1000][1000];
int dx[4] = { 1, -1 ,0 ,0 };
int dy[4] = { 0, 0, -1, 1 };

struct node {
	int x, y, wall, dist;
};

int bfs(int k, int n, int m) {
	queue<node> q;
	q.push({ 0, 0, k, 1 });
	for (int i = 0; i <= k; i++) {
		visit[i][0][0] = true;
	}
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		if (cur.x == n - 1 && cur.y == m - 1)
		{
			return cur.dist;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == '0') {
				if (visit[cur.wall][nx][ny] == false) {
					q.push({ nx,ny,cur.wall,cur.dist + 1 });
					visit[cur.wall][nx][ny] = true;
				}
			}
			else {
				if (cur.wall > 0 && visit[cur.wall][nx][ny] == false)
				{
					q.push({ nx,ny,cur.wall - 1,cur.dist + 1 });
					visit[cur.wall][nx][ny] = true;
				}
			}
		}
	}
	return -1;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	cout << bfs(k,n,m) << '\n';
	return 0;
}