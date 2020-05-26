#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check[13];
int ans[13];

void go(vector<int>& temp, int index, int prev, int n) {
	if (n - prev <= 6 - index) return;
	if (index == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
	}
	for (int i = prev + 1; i < n; i++) {
		if (check[i]) continue;
		check[i] = true;
		ans[index] = temp[i];
		go(temp, index + 1, i, n);
		check[i] = false;
	}
	return;
}

int main() {
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> q(n);
		for (int i = 0; i < n; i++) {
			cin >> q[i];
		}
		go(q, 0, -1, n);
		cout << '\n';
	}
}