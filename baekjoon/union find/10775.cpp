#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//최적화된 disjoint set 기준
//출처: https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html
struct DisjointSet {
	vector<int> parent;
public://공개 멤버, 외부에서도 확인 가능
	DisjointSet(int n) : parent(n) {
		// 1. 초기화 
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		} 
	}// find: u 가 속한 트리의 루트 노드 번호를 반환한다.
	int find (int u) {
		if (u == parent[u]) return u; 
		return parent[u] = find(parent[u]);
	}
	// merge: u 가 속한 트리와 v 가 속한 트리를 합친다. 
	void merge (int u, int v){ 
		u = find(u); 
		v = find(v); 
		parent[u] = v;
		return;
	} 
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int g, p;
	cin >> g >> p;
	DisjointSet set(g + 1);
	int ans = 0;
	for (int i = 0; i < p; i++) {
		int maxRank;
		cin >> maxRank;
		int isFull = set.find(maxRank);
		if (isFull != 0) {
			set.merge(isFull, isFull - 1);
			ans += 1;
		}
		else {
			break;
		}
	}
	cout << ans <<'\n';
}