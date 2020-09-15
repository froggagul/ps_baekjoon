#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define INF 2e9;
typedef pair<int, int> pii;
int n;
int graph[130][130];
int dist[130][130];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
priority_queue<pair<int, pii>> pq;

int main(void) {
	int cnt = 1;
	while (1) {
		// input
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &graph[i][j]);	// 가중치 입력
				dist[i][j] = INF;	//dist 초기화
			}
		}
		dist[0][0] = 0;
		pq.push(make_pair(0, make_pair(0, 0)));
		while (!pq.empty()) {
			int cost = -pq.top().first;
			pii here = pq.top().second;
			int x = here.first;
			int y = here.second;
			pq.pop();
			if (dist[x][y] < cost) continue;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
						int nextCost = cost + graph[x][y];
						if (dist[nx][ny] > nextCost) {
							dist[nx][ny] = nextCost;
							pq.push(make_pair(-nextCost, make_pair(nx, ny)));
						}
					}
				}
			}
		}
		printf("Problem %d: %d\n", cnt, dist[n - 1][n - 1] + graph[n - 1][n - 1]);
		cnt += 1;
	}
	return 0;
}