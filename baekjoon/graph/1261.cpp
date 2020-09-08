#include <iostream>
#include <deque>
#include <utility>
using namespace std;

#define MAX 101

bool wall[MAX][MAX];
int visit[MAX][MAX];
deque<pair<int,int>> dq;	//x, y
int dx[4] = { -1 ,1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			wall[i][j] = temp - '0';
			visit[i][j] = -1;
		}
	}
	dq.push_back({ 0, 0 });
	visit[0][0] = 0;
	while (!dq.empty()) {
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (visit[nx][ny] == -1) {
					if (!wall[nx][ny]) {
						visit[nx][ny] = visit[x][y];
						dq.push_front({ nx, ny });
					}
					else {
						visit[nx][ny] = visit[x][y] + 1;
						dq.push_back({nx, ny});
					}
				}
			}
		}
	}
	cout << visit[n - 1][m - 1] << "\n";
	return 0;
}