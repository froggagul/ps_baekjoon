#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
string map[50];
int deprecated[50][50];	//몇초에 이동할 수 없게 되는지
bool visit[50][50];		//방문 했는지
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
struct node {
	int x, y, time;
};
queue<node> q;
int main() {
	int m, n;
	cin >> m >> n;
	char temp;
	node start;
	for (int i = 0; i < m; i++) {
		cin >> map[i];
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '*') {
				q.push({ i, j, 0 });
				deprecated[i][j] = 0;
			}
			else {
				deprecated[i][j] = -1;
				if (map[i][j] == 'S') {
					visit[i][j] = true;
					start = { i, j, 0 };
				}
			}
		}
	}
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		int nt = cur.time + 1;
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (map[nx][ny] != '.') continue;
			if (deprecated[nx][ny] == -1) {
				deprecated[nx][ny] = nt;
				q.push({ nx, ny, nt });
			}
		}
	}
	q.push(start);
	int min = -1;
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		if (map[cur.x][cur.y] == 'D') {
			if (cur.time < min || min == -1) {
				min = cur.time;
			}
		}
		int nt = cur.time + 1;
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (map[nx][ny] != '.' && map[nx][ny] != 'D') continue;
			if (deprecated[nx][ny] != -1 && deprecated[nx][ny] <= nt) continue;
			if (!visit[nx][ny]) {
				visit[nx][ny] = true;
				q.push({ nx, ny, nt });
			}
		}
	}
	if (min == -1) {
		cout << "KAKTUS" << '\n';
	}
	else {
		cout << min << '\n';
	}
	return 0;
}