#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int check[3001]; // 0: not visited, 1: visited, 2: cycle
int dist[3001];
vector<int> g[3001];
queue<int> q;
int n;

int go(int x, int p) {
	// return 값이
	// -2: 사이클 찾음, 포함되지 않음, -1: 사이클 못 찾음, 0~n-1: 사이클 찾음, 시작 인덱스
	if (check[x] == 1) return x;
	check[x] = 1;
	for (int y : g[x]) {
		if (y == p) continue;
		int res = go(y, x);
		if (res == -2) return -2;
		if (res >= 0) {
			check[x] = 2;
			if (x == res) return -2; else return res;
		}
	}
	return -1;
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int from, to;
		cin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
		check[i] = -1;
	}
	go(1, -1);
	for (int i = 1; i <= n; i++) {
		if (check[i] == 2) {
			q.push(i);
			dist[i] = 0;
		}
		else {
			dist[i] = -1;
		}
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : g[x]) {
			if (dist[y] == -1) {
				q.push(y);
				dist[y] = dist[x] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << dist[i] << ' ';
	}
	cout << '\n';
	return 0;
}