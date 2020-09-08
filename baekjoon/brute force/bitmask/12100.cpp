#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int limit = 5;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool isValid(vector<int> dir) {
	for (int i = 1; i < limit; i++) {
		if (dir[i] == dir[i - 1]) return false;
	}
	return true;
}

vector<int> gen(int k) {
	vector<int> dir(limit);
	for (int i = 0; i < limit; i++) {
		dir[i] = k & 3;
		k >>= 2;
	}
	return dir;
}

bool simulate(vector<vector<int>>& map, int x, int y, int k, int &max, vector<vector<bool>>& isMulti) {
	int n = map.size();
	int from = map[x][y];
	if (from == 0) return false;
	int nx = x + dx[k];
	int ny = y + dy[k];
	if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
		int to = map[nx][ny];
		if (to == 0) {
			while (true) {
				nx = nx + dx[k];
				ny = ny + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (map[nx][ny] == 0) {
						continue;
					}
					else if (map[nx][ny] == from) {
						if (!isMulti[nx][ny]) {
							map[x][y] = 0;
							map[nx][ny] = 2 * from;
							isMulti[nx][ny] = true;
							if (max < 2 * from) {
								max = 2 * from;
							}
						}
						else {
							map[x][y] = 0;
							nx = nx - dx[k];
							ny = ny - dy[k];
							map[nx][ny] = from;
						}
						break;
					}
				}
				map[x][y] = 0;
				nx = nx - dx[k];
				ny = ny - dy[k];
				map[nx][ny] = from;
				break;
			}
			return true;
		}
		else if (from == to) {
			if (!isMulti[nx][ny]) {
				map[x][y] = 0;
				map[nx][ny] = 2 * from;
				isMulti[nx][ny] = true;
				if (max < 2 * from) {
					max = 2 * from;
				}
			}
			return true;
		}
	}
	return false;
}

int go(vector<vector<int>> map, vector<int>& dir) {
	int n = map.size();
	int max = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (max < map[i][j]) {
				max = map[i][j];
			}
		}
	}
	/*
	int i = 0;
	int temp[5] = { 3,2,0,1,0 };
	for (int k : dir) {
		if (k != temp[i++]) return max;
	}
	*/
	for (int k : dir) {
		vector<vector<bool>> isMulti(n, vector<bool>(n, false));
		if (k == 3 || k == 1) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					simulate(map, i, j, k, max, isMulti);
				}
			}
			/*
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << map[i][j] << " ";
				}
				cout << '\n';
			}
			cout << '\n';
			*/
		}
		else if (k == 0 || k == 2) {
			for (int i = n - 1; i >= 0; i--) {
				for (int j = n - 1; j >= 0; j--) {
					simulate(map, i, j, k, max, isMulti);
				}
			}
			/*
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << map[i][j] << " ";
				}
				cout << '\n';
			}
			cout << '\n';
			*/
		}
	}
	return max;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 2;
	for (int i = 0; i < (1 << (2 * limit)); i++) {
		vector<int> dir = gen(i);
		int cur = go(map, dir);
		if (cur > ans) {
			ans = cur;
		}
	}
	cout << ans << '\n';
	return 0;
}