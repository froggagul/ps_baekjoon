#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int v, e;
vector<int> graph[10001];
int visited[10001];
int clk = 0;
bool fin[10001];
stack<int> s;
vector<vector<int>> ans;

int dfs(int x) {
	visited[x] = ++clk;
	s.push(x);
	int parent = visited[x];
	for (auto i : graph[x]) {
		if (!visited[i]) parent = min(parent, dfs(i));
		else if (!fin[i]) parent = min(parent, visited[i]);
	}
	if (parent == visited[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			fin[t] = 1;
			if (t == x) break;
		}
		ans.push_back(scc);
	}
	return parent;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	int from, to;
	while (e--) {
		cin >> from >> to;
		graph[from].push_back(to);
	}
	for (int i = 1; i <= v; i++) {
		if (!visited[i]) dfs(i);
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		sort(ans[i].begin(), ans[i].end());
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		for (auto j : ans[i]) cout << j << " ";
		cout << -1 << '\n';
	}
	return 0;
}