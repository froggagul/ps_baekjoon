#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int map[22][22];
bool eaten[22][22];
bool visit[22][22];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
struct node {
	int x, y, time;
};

int main() {
	int n;
	cin >> n;
	node start = { 0, 0, 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				start = { i, j, 0 };
				map[i][j] = 0;
			}
		}
	}
	int size = 2;
	int eatCount = 0;
	bool isContinue = true;
	while (isContinue) {
		queue<node> q;
		q.push(start);
		memset(visit, 0, sizeof(visit));
		visit[start.x][start.y] = true;
		bool isMoved = false;
		int minTime = -1;
		while (!q.empty()) {
			node cur = q.front();
			q.pop();
			if (map[cur.x][cur.y] > 0 && map[cur.x][cur.y] < size && !eaten[cur.x][cur.y] && (minTime == -1 || minTime == cur.time)) {
				if (minTime == -1) {
					eaten[cur.x][cur.y] = true;
					minTime = cur.time;
					start = cur;
					isMoved = true;
				}
				else {
					if (start.x > cur.x) {
						eaten[start.x][start.y] = false;
						eaten[cur.x][cur.y] = true;
						start = cur;
					}
					else if (start.x == cur.x && start.y > cur.y) {
						eaten[start.x][start.y] = false;
						eaten[cur.x][cur.y] = true;
						start = cur;
					}
				}
			}
			int nt = cur.time + 1;
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (!visit[nx][ny] && size >= map[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx, ny, nt });
				}
			}
		}
		if (isMoved) {
			eatCount += 1;
			if (eatCount == size) {
				size += 1;
				eatCount = 0;
			}
		}
		isContinue = isMoved;
	}
	cout << start.time << '\n';
	return 0;
}