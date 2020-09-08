#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

char a[20][20];
int n, m;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 ,0 };
int ans = -1;

int check(pair<int, int>s1, pair<int, int>s2) {
	int fallen = 0;
	if (s1.first >= n || s1.first<0 || s1.second >= m || s1.second < 0) {
		fallen += 1;
	}
	if (s2.first >= n || s2.first < 0 || s2.second >= m || s2.second < 0) {
		fallen += 1;
	}
	return fallen;
}

int go(pair<int, int> s1, pair<int, int> s2, int cnt) {
	if (cnt == 11) {
		return -1;
	}
	if (check(s1, s2) == 2) return -1;
	if (check(s1, s2) == 1) return cnt;

	int ans = -1;
	for (int i = 0; i < 4; i++) {
		int x1 = s1.first + dx[i];
		int y1 = s1.second + dy[i];
		int x2 = s2.first + dx[i];
		int y2 = s2.second + dy[i];
		if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && a[x1][y1] == '#') {
			x1 = s1.first;
			y1 = s1.second;
		}
		if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m && a[x2][y2] == '#') {
			x2 = s2.first;
			y2 = s2.second;
		}
		auto ns1 = make_pair( x1, y1 );
		auto ns2 = make_pair( x2, y2 );
		int temp = go(ns1, ns2, cnt + 1);
		if (temp == -1) continue;
		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;
	pair<int, int> s[2];
	int k = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'o') {
				s[k] = { i, j };
				k++;
			}
		}
	}
	cout << go(s[0], s[1], 0) << '\n';
	return 0;
}