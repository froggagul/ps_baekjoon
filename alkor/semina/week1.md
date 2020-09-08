최단경로
====

최단경로의 종류
* 하나의 정점에서 다른 하나의 정점
* 하나의 정점에서 다른 모든 정점
* 하나의 목적지로 가는 모든 최단 경로
* 모든 최단 경로

DFS/BFS
* DFS: O(V+E) (인접리스트 구현시)
* 모든 간선의 길이가 같다면 BFS를 이용하자
    * BFS: O(B+E) (인접리스트 구현시)


다익스트라
====
* 한 정점에서부터 다른 모든 정점으로의 최단 경로를 구하는 알고리즘
* **음수 사이클이 있으면, 최단 경로를 구할 수 없다.**
* 시간복잡도: O(V^2) (단순구현)

알고리즘
----
*

다익스트라 알고리즘의 증명
----


```c++
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <set>
#include <vector>
#include<utility>
using namespace std;

const int INF = 2e9;
typedef pair<int, int> pii;
vector<pii> graph[20005];
int dist[20005];
int n, m, start, a, b, c;

int main() {
	scanf("%d %d %d ", &n, &m, &start);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c });
	}
	for (int i = 0; i < n; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	return 0;
}
```

벨만포드
====
* 음수 가중치를 가지는 간선이 있어도 원래 시간복잡도 안으로 작동한다.
* 시간복잡도 O(VE)
n-1과 n번째 dist 배열을 비교해서
음수 사이클이 있는지 알 수 있음

플로이드-와샬
=====
모든 간성