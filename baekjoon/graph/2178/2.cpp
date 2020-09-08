#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, c;
char arr[105][105] = { 0 };
int visit[105][105] = { 0 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
struct node {
	int x, y;
};
queue<node> q;

int main() {
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", &arr[i]);
	}
	q.push({ 0, 0 });
	visit[0][0] = 1;
	while (!q.empty()) {
		node front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (visit[nx][ny] == 0 && arr[nx][ny] == '1') {
					q.push({ nx, ny });
					visit[nx][ny] = visit[front.x][front.y] + 1;
				}
			}
		}
	}
	printf("%d", visit[n - 1][m - 1]);
	return 0;
}