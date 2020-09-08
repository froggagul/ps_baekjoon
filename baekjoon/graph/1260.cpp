#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool check[1001];
vector<int> g[1001];
queue<int> q;

void bfs() {
	while (!q.empty()) {
		int start = q.front();
		check[start] = true;
		cout << start << " ";
		for (int i = 0; i < g[start].size(); i++) {
			int y = g[start][i];
			if (!check[y]) {
				check[y] = true;
				q.push(y);
			}
		}
		q.pop();
	}
	return;
}

void dfs(int x) {
	cout << x << " ";
	check[x] = true;
	sort(g[x].begin(), g[x].begin() + g[x].size());
	for (int i = 0; i < g[x].size(); i++) {
		int y = g[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}
	return;
}

int main() {
	int n, m, start;
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	dfs(start);
	cout << '\n';
	for (int i = 1; i <= n; i++) {
		check[i] = false;
	}
	q.push(start);
	bfs();
	return 0;
}