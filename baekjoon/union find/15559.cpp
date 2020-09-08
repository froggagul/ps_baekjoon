#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

//최적화된 disjoint set 기준
//출처: https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html
struct DisjointSet {
	vector<int> parent, rank;
	int treeNum;
public://공개 멤버, 외부에서도 확인 가능
	DisjointSet(int n) : parent(n), rank(n, 1) {
		// 1. 초기화 
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		} 
		treeNum = n;
	}// find: u 가 속한 트리의 루트 노드 번호를 반환한다.
	int find (int u) {
		if (u == parent[u]) return u; 
		return parent[u] = find(parent[u]);
	}
	// merge: u 가 속한 트리와 v 가 속한 트리를 합친다. 
	void merge (int u, int v){ 
		u = find(u); 
		v = find(v); 
		// u와 v의 root가 같으면 merge X
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		treeNum -= 1;
		// 두 트리의 높이가 같은 경우에는 결과 트리의 rank 를 1 높혀준다. 
		if (rank[u] == rank[v]) ++rank[v];
	} 
};

void go(int prev, int m, int x, int y, vector<string>& map, vector<vector<bool>>& check ,DisjointSet& set) {
	int index = x * m + y;
	if (check[x][y]) {
		set.merge(prev, index);
		return;
	}
	check[x][y] = true;
	if (prev != -1) {
		set.merge(prev, index);
	}
	if (map[x][y] == 'E') {
		return go(index, m, x, y + 1, map, check, set);
	}
	else if (map[x][y] == 'W') {
		return go(index, m, x, y - 1, map, check, set);
	}
	else if (map[x][y] == 'S') {
		return go(index, m, x + 1, y, map, check, set);
	}
	else if (map[x][y] == 'N') {
		return go(index, m, x - 1, y, map, check, set);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	DisjointSet set(n * m);
	vector<string> map(n);
	vector<vector<bool>> check(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	int cnt = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j]) {
				go(-1, m, i, j, map, check, set);
			}
		}
	}
	cout << set.treeNum << '\n';
}