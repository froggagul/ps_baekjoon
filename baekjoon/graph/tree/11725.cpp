#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100001

vector<int> g[MAX];
bool check[MAX];
int parents[MAX];
queue<int> q;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int from, to;
		cin >> from >> to;
		g[to].push_back(from);
		g[from].push_back(to);
	}
	q.push(1);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i = 0; i < g[curr].size(); i++) {
			int son = g[curr][i];
			if (!check[son]) {
				check[son] = true;
				parents[son] = curr;
				q.push(son);
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << parents[i] << '\n';
	}
	return 0;
}