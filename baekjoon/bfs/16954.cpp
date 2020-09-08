#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

string map[8];		// [i][j] i초후 map 상태
bool visit[9][8][8];
struct node {
	int x, y, time;
};
int main() {
	for (int i = 0; i < 8; i++) {
		cin >> map[i];
	}

	queue<node> q;
	q.push({7, 0, 0});
	visit[0][7][0] = true;
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		if (cur.x == 0 && cur.y == 7) {
			cout << 1 << '\n';
			return 0;
		}
		int nt = min(cur.time + 1, 8);
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int nx = cur.x + i;
				int ny = cur.y + j;
				if (!(0 <= ny && ny < 8 && 0 <= nx && nx < 8)) continue;
				if (nx - cur.time >= 0 && map[nx - cur.time][ny] == '#') continue;
				if (nx - cur.time - 1 >= 0 && map[nx - cur.time - 1][ny] == '#') continue;
				if (!visit[nt][nx][ny]) {
					visit[nt][nx][ny] = true;
					q.push({ nx, ny, nt });
				}
			}
		}
	}
	cout << 0 << '\n';
	return 0;
}