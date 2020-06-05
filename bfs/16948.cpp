#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dx[6] = { -2, -2, 0, 0, 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1, 1 };

int main() {
	int n;
	cin >> n;
	vector<vector<bool>> visit(n, vector<bool>(n, false));
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	queue<pair<pair<int, int>, int>> q;
	q.push({ {x1, y1}, 0 });
	visit[x1][y1] = true;
	while (!q.empty()) {
		int cnt = q.front().second;
		int x = q.front().first.first;
		int y = q.front().first.second;
		q.pop();
		if (x == x2 && y == y2) {
			cout << cnt << '\n';
			return 0;
		}
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ {nx, ny}, cnt + 1 });
				}
			}
		}
	}
	cout << -1 << '\n';
	return 0;
}