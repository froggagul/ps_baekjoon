#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int v, e;
vector<int> graph[20005];
vector<vector<int>> ans;
int clk = 0;
int visited[20005];
bool finished[20005];
stack <int> s;

int dfs(int x) {
	visited[x] = ++clk;
	s.push(x);
	int parent = visited[x];
	for (auto i : graph[x]) {
		if (!visited[i]) {
			parent = min(parent, dfs(i));
		}
		else if (!finished[i]) {
			parent = min(parent, visited[i]);
		}
	}
	if (parent == visited[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		ans.push_back(scc);
	}
	return parent;
}
int inv(int a) {
	return a & 1 == 0 ? a - 1 : a + 1;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v >> e;
	int from, to;
	while (e--) {
		cin >> from >> to;
		from = from < 0 ? -2 * from : 2 * from - 1;
		to = to < 0 ? -2 * to : 2 * to - 1;
		graph[inv(from)].push_back(to);
		graph[inv(to)].push_back(from);
	}
	for (int i = 1; i <= v * 2; i++) {
		if (!visited[i]) dfs(i);
	}
	for (int i = 0; i < ans.size(); i++) {
		sort(ans[i].begin(), ans[i].end());
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < (int)ans[i].size() - 1;j++) {
			if ((ans[i][j + 1] + 1) / 2 == (ans[i][j] + 1) / 2) {
				cout << 0 << '\n';
				return 0;
			}
		}
	}
	cout << 1 << '\n';
	return 0;
}