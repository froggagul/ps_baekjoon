#include <iostream>
#include<vector>
#include<queue>
using namespace std;

bool check[100002]; // 0: not visited, 1 이상 : 시작점으로부터의 거리
int parent[100002];
int question[100002];
vector<int> g[100002];
queue<int> q;
int n;

void bfs(int init) {
	q.push(init);
	check[init] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < g[now].size(); i++) {
			int son = g[now][i];
			if (check[son]) continue;
			check[son] = true;
			parent[son] = now;
			q.push(son);
		}
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int from, to;
		cin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	bfs(1);
	for (int i = 0; i < n; i++) {
		cin >> question[i];
		check[question[i]] = false;
	}
	int index = 1;
	q.push(1);
	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			cout << 0 << '\n';
			return 0;
		}
		int x = q.front(); q.pop();
		check[x] = true;
		if (x != question[i]) {
			cout << 0 << '\n';
			return 0;
		}
		int cnt = 0;
		for (int y : g[x]) {
			if (check[y] == false) {
				parent[y] = x; 
				cnt += 1;
			}
		}
		for (int j = 0; j < cnt; j++) {
			if (index + j >= n || parent[question[index + j]] != x) {
			// x와 연결되지 않은 정점이 큐에 들어가있으니 올바르지 않음
				cout << 0 << '\n';
				return 0;
			}
			q.push(question[index + j]);
			check[question[index + j]] = true;
		}
		index += cnt;
	}
	
	cout << 1 << '\n';
	return 0;
}