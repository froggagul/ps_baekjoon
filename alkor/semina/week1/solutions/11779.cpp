#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
typedef pair<int, int> pii;
int v, e, a, b, c, start, goal;
vector<pii> graph[1005];
int dist[1005];		//dist[i]: start에서 i vertex의 최단 경로 길이
int parent[1005];	//parent[i]: i vertex의 부모, 최단 경로 추측시 사용
priority_queue<pii> pq;

int main() {
	// input
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
	}
	scanf("%d %d", &start, &goal);
	// 초기화
	for (int i = 1; i <= v; i++) dist[i] = INF;
	dist[start] = 0;
	parent[start] = start;	// start의 부모는 자기 자신
	// 다익스트라 알고리즘
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i].first;
			int nextCost = graph[here][i].second + cost;
			if (dist[there] > nextCost) {
				dist[there] = nextCost;
				parent[there] = here;
				pq.push(make_pair(-nextCost, there));
			}
		}
	}
    // 경로 구하기
	vector<int> order;
	order.push_back(goal);
	int curr = goal;
	int cnt = 1;
	do {
		order.push_back(parent[curr]);
		cnt += 1;
		curr = parent[curr];
	} while (parent[curr] != curr);
    // output
	printf("%d\n", dist[goal]);
	printf("%d\n", cnt);
	for (int i = order.size() - 1; i >= 0; i--) {
		printf("%d ", order[i]);
	}
    return 0;
}