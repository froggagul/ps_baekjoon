#include<iostream>
#include<utility>
#include<queue>
using namespace std;

bool check[100][100] = { 0 };
int a[100][100] = { 0 };
queue<pair<int, int>> q;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	int lastX, lastY;
	cin >> lastY >> lastX;

	for (int i = 0; i < lastY; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < lastX; j++) {
			check[i][j] = temp[j] - '0';
		}
	}
	lastX -= 1;
	lastY -= 1;
	q.push({ 0, 0 });
	a[0][0] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx <= lastX && ny >= 0 && ny <= lastY) {
				if (a[ny][nx] == 0 && check[ny][nx]) {
					a[ny][nx] = a[y][x] + 1;
					check[ny][nx] = false;
					q.push({ ny, nx });
				}
			}
		}
	}
	cout << a[lastY][lastX] << '\n';
	return 0;
}