#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int v, e, a, b, c;
int graph[405][405];	// a -> b 가중치

int main() {
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) continue;
			graph[i][j] = INF;
		}
	}
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
	}
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	int ans = INF * 2;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i != j && graph[i][j] != INF && graph[j][i] != INF) {
				ans = min(ans, graph[i][j] + graph[j][i]);
			}
		}
	}
	if (ans == INF * 2) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ans);
	}
	return 0;
}