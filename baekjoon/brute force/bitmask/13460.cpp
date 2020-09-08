#include<iostream>
#include<vector>
#include<string>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

const int limit = 10;

vector<int> gen(int k) {
	vector<int> dir(limit);
	for (int i = 0; i < limit; i++) {
		dir[i] = k & 3;	//dir[i] = k % 4;
		k >>= 2;		//k /= 4;
	}
	return dir;
}

bool isValidDir(vector<int>& dir) {
	int len = dir.size();
	for (int i = 1; i < len; i++) {
		int dir1 = dir[i - 1];
		int dir2 = dir[i];
		if (dir1 == dir2) return false;		//0,0 or 1,1 or 2,2 or 3,3
		if (dir1 + dir2 == 1) return false;	//0,1 or 1,0
		if (dir1 + dir2 == 5) return false;	//2,3 or 3,2
	}
	return true;
}

pair<bool, bool> simulate(vector<string>& map, int k, int& x, int& y) {
	bool moved = false, holein = false;
	int n = map.size();
	int m = map[0].size();
	while (true) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			return make_pair(moved, false);
		}
		if (map[nx][ny] == '.') {
			swap(map[nx][ny], map[x][y]);
			x = nx;
			y = ny;
			moved = true;
		}
		else if (map[nx][ny] == '#') {
			holein = false;
			return make_pair(moved, holein);
		}
		else if (map[nx][ny] == 'R' || map[nx][ny] == 'B') {
			holein = false;
			return make_pair(moved, holein);
		}
		else if (map[nx][ny] == 'O') {
			map[x][y] = '.';
			moved = true;
			holein = true;
			return make_pair(moved, holein);
		}
	}
	return make_pair(false, false);
}

int go(vector<string> map, vector<int>& dir) {
	int n = map.size();
	int m = map[0].size();
	int rx, ry, bx, by, ox, oy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'O') {
				ox = i;
				oy = j;
			}
			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			if (map[i][j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}//빨간색, 파란색 구슬, 구멍의 좌표 알아내기
	int cnt = 0;
	for (int k : dir) {
		cnt += 1;
		while (true) {
			auto redResult = simulate(map, k, rx, ry);
			auto blueResult = simulate(map, k, bx, by);
			if (blueResult.second) {
				return -1;	
			}
			else {
				if (redResult.second) {
					return cnt;
				}
			}
			if (!redResult.first && !blueResult.first) {
				break;
			}
		}
	}
	return -1;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> map(n);
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	int ans = -1;
	for (int i = 0; i < (1 << (limit * 2)); i++) {
		vector<int> dir = gen(i);
		if (isValidDir(dir)) {
			int cnt = -1;
			int cur = go(map, dir);
			if (cur == -1) continue;
			if (ans > cur || ans == -1) {
				ans = cur;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}