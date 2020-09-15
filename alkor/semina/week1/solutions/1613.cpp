#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int v, e, a, b, t;
// graph[a][b] : graph상으로 경로가 존재한다.
// 문제상으로는 a가 b보다 먼저 일어났다. 시간상, time_a < time_b
bool graph[405][405];


int main() {
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) graph[i][i] = true;
	for (int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = true;
	}
    // 플로이드 와샬
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
			}
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		if (graph[a][b]) {
            // a가 b보다 먼저 일어났다면
			printf("-1\n");
		}
		else if (graph[b][a]) {
            // b가 a보다 먼저 일어났다면
			printf("1\n");
		}
		else {
            // 모른다면
			printf("0\n");
		}
	}
	return 0;
}