#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100001

vector<pair<int, int>> g[MAX];
bool check[MAX];
queue<pair<int, int>> q;


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int from, to, len;
		cin >> from >> to >> len;
		g[from].push_back({ to, len });
		g[to].push_back({ from, len });
	}
	q.push({ 1, 0 });
	check[1] = true;
	int maxLen = 0;
	int maxNode = 1;
	while (!q.empty()) {
		int currNode = q.front().first;
		int currLen = q.front().second;
		if (currLen > maxLen) {
			maxLen = currLen;
			maxNode = currNode;
		}
		q.pop();
		for (int i = 0; i < g[currNode].size(); i++) {
			int son = g[currNode][i].first;
			int len = g[currNode][i].second;
			if (!check[son]) {
				check[son] = true;
				q.push({ son, currLen + len });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		check[i] = false;
	}
	q.push({ maxNode, 0 });
	check[maxNode] = true;
	maxLen = 0;
	while (!q.empty()) {
		int currNode = q.front().first;
		int currLen = q.front().second;
		if (currLen > maxLen) {
			maxLen = currLen;
			maxNode = currNode;
		}
		q.pop();
		for (int i = 0; i < g[currNode].size(); i++) {
			int son = g[currNode][i].first;
			int len = g[currNode][i].second;
			if (!check[son]) {
				check[son] = true;
				q.push({ son, currLen + len });
			}
		}
	}
	cout << maxLen << '\n';
	return 0;
}