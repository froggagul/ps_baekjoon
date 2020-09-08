#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> road[101];
bool visit[100];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int from, to;
		cin >> from >> to;
		road[from].push_back(to);
	}
	queue<pair<int, int>> q;
	q.push({1, 0});
	visit[1] = true;
	while (!q.empty()) {
		int curr = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (road[curr].size() == 1) {
			curr = road[curr][0];
		}
		if (curr == 100) {
			cout << cnt << '\n';
			return 0;
		}
		for (int i = 1; i <= 6; i++) {
			if (!visit[curr + i]) {
				visit[curr + i] = true;
				q.push({ curr + i, cnt + 1 });
			}
		}
	}
	return 0;
}