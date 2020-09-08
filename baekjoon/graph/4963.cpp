#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;

bool check[50][50] = { 0 };
bool a[50][50] = { 0 };
queue<pair<int, int>> q;

int bfs(int startX, int startY, int n, int m) {
	q.push({ startX, startY });
	int count = 0;
	while (!q.empty()) {
		count += 1;
		pair<int, int> curr = q.front();
		// cout << curr.first << curr.second << '\n';
		int x = curr.first;
		int y = curr.second;
		check[x][y] = true;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) continue;	//중복이지만 가독성을 위해 추가
				if (x + i >= 0 && x + i < m) {
					if (y + j >= 0 && y + j < n) {
						if (check[x + i][y + j] || !a[x + i][y + j]) continue;
						q.push({ x + i, y + j });
						check[x + i][y + j] = true;
					}
				}
			}
		}
		q.pop();
	}
	return count;
}


int main() {

	while (1) {
		int n, m; //너비, 높이
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		for (int i = 0; i < m; i++) {//높이
			for (int j = 0; j < n; j++) {//너비
				cin >> a[i][j];
			}
		}
		int count = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!a[i][j]) continue;
				if (!check[i][j]) {
					bfs(i, j, n, m);
					count += 1;
				}
			}
		}
		cout << count << '\n';
		for (int i = 0; i < m; i++) {//높이
			for (int j = 0; j < n; j++) {//너비
				a[i][j] = 0;
				check[i][j] = 0;
			}
		}
	}
	return 0;
}