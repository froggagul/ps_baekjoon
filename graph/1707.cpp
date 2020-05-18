#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;

int check[20001];
vector<int> g[20001];
queue<pair<int, bool>> q;

bool bfs(int start) {
	q.push({ start, false });
	while (!q.empty()) {
		int curr = q.front().first;
		bool currTeam = q.front().second;
		check[curr] = true;
		if (currTeam) {
			check[curr] = 1;
		}
		else {
			check[curr] = 2;
		}
		for (int i = 0; i < g[curr].size(); i++) {
			int y = g[curr][i];
			if (!check[y]) {
				check[y] = true;
				q.push({ y, !currTeam });
			}
		}
		q.pop();
	}
	return true;
}


int main() {
	int num;
	cin >> num;
	while (num--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			check[i] = false;
			g[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int from, to;
			cin >> from >> to;
			g[from].push_back(to);
			g[to].push_back(from);
		}
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				bfs(i);
			}
		}
		bool valid = true;
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < g[i].size(); k++) {
				int j = g[i][k];
				if (check[i] == check[j]) {
					valid = false;
				}
			}
		}
		if (valid) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}