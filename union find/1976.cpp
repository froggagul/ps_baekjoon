#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct DisjointSet {
	vector<int> root, rank;
	DisjointSet(int n) : root(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			root[i] = i;
		}
	}
	int find(int u) {
		if (u == root[u]) return u;
		return root[u] = find(root[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;

		if (rank[u] > rank[v]) swap(u, v);
		root[u] = v;
		if (rank[u] == rank[v]) rank[v] += 1;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	DisjointSet set(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool isConnected;
			cin >> isConnected;
			if (isConnected) {
				set.merge(i, j);
			}
		}
	}
	int root;
	for (int i = 0; i < m; i++) {
		int curr;
		cin >> curr;
		curr -= 1;
		if (i == 0) {
			root = set.find(curr);
		}
		else {
			if (root != set.find(curr)) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	cout << "YES" << '\n';
	return 0;
}