#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int v, e, a, b;
// graph[a][b] : graph상으로 경로가 존재한다.
bool graph[505][505];


int main() {
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) graph[i][i] = true;
	for (int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = true;
	}
    // 플로이드 와샬 알고리즘
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
			}
		}
	}
    // 만약 i -> j 혹은 j -> i가 없다면, 이는 i 와 j간의 키 순서가 명확하지 않음을 의미한다.
    // 한명이라도 키순서가 명확하지 않다면, 등수가 명확하지 않다.
	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		bool check = true;
		for (int j = 1; j <= v; j++) {
			if (i == j) continue;
			if (graph[i][j] || graph[j][i]) continue;
			check = false;
		}
		if (check) cnt += 1;
	}
	printf("%d\n", cnt);
	return 0;
}