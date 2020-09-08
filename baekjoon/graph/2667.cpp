#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;

bool check[25][25] = { 0 };
bool a[25][25] = { 0 };
queue<pair<int, int>> q;

int bfs(int startX, int startY, int n) {
	q.push({ startX,startY });
	int count = 0;
	while (!q.empty()) {
		count += 1;
		pair<int, int> curr = q.front();
		int x = curr.first;
		int y = curr.second;
		check[x][y] = true;
		if (x > 0) {
			if (!check[x - 1][y] && a[x - 1][y]) {
				q.push({ x - 1, y });
				check[x - 1][y] = true;
			}
		}
		if (y > 0) {
			if (!check[x][y - 1] && a[x][y - 1]) {
				q.push({ x, y - 1 });
				check[x][y - 1] = true;
			}
		}
		if (x < n - 1) {
			if (!check[x + 1][y] && a[x + 1][y]) {
				q.push({ x + 1, y });
				check[x + 1][y] = true;
			}
		}
		if (y < n - 1) {
			if (!check[x][y + 1] && a[x][y + 1]) {
				q.push({ x, y + 1 });
				check[x][y + 1] = true;
			}
		}
		q.pop();
	}
	return count;
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			a[i][j] = temp[j] - '0';
		}
	}
	int count = 0;
	vector<int> countArray;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!a[i][j]) continue;
			if (!check[i][j]) {
				count += 1;
				countArray.push_back(bfs(i, j, n));
			}
		}
	}
	sort(countArray.begin(), countArray.end());
	cout << count << '\n';
	for (int i = 0; i < countArray.size(); i++) {
		cout << countArray[i] << '\n';
	}
	return 0;
}