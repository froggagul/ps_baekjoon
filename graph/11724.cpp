#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool check[1001] = { 0 };
vector<int> g[1001];
queue<int> q;

void bfs() {
	while (!q.empty()) {
		int start = q.front();
		check[start] = true;
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


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			count += 1;
			q.push(i);
			bfs();
		}
	}
	cout << count << '\n';
	return 0;
}