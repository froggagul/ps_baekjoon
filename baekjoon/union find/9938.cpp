#include<iostream>
#include<vector>

using namespace std;

int parent[300001];
bool visited[300001];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	parent[u] = v;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < L; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		a -= 1; b -= 1;
		if (!visited[a]) {
			visited[a] = true;
			merge(a, b);
			cout << "LADICA" << '\n';
		}
		else if (!visited[b]) {
			visited[b] = true;
			merge(b, a);
			cout << "LADICA" << '\n';
		}
		else if (!visited[find(parent[a])]) {
			visited[find(parent[a])] = true;
			merge(a, b);
			cout << "LADICA" << '\n';
		}
		else if (!visited[find(parent[b])]) {
			visited[find(parent[b])] = true;
			merge(b, a);
			cout << "LADICA" << '\n';
		}
		else {
			cout << "SMECE" << '\n';
		}
	}
	return 0;
}