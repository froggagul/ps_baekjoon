#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

bool check_row[10][10];			//i번째 row의 j의 사용 여부 check_row[i][j]
bool check_col[10][10];			//i번째 row의 j의 사용 여부 check_row[i][j]
bool check_block[10][10];		//i번째 block의 j의 사용 여부 check_row[i][j]
bool check_domino[10][10];		//도미노 ij(i<j)의 사용여부 check_domino[i][j]
int a[10][10];
int dRow[2] = { 1, 0 };
int dCol[2] = { 0, 1 };

int coorToBlockCount(int x, int y) {
	return (x / 3) * 3 + y / 3;
}

pair<int, int> stringToCoordinate(string str) {
	return make_pair(str[0] - 'A', str[1] - '1');
}

bool isValid(int row, int col, int num) {
	if (check_row[row][num]) return false;
	if (check_col[col][num]) return false;
	if (check_block[coorToBlockCount(row, col)][num]) return false;
	return true;
}

bool isValidDomino(int num1, int num2) {
	if (num1 == num2) return false;
	if (check_domino[num1][num2]) return false;
	return true;
}

void check(int x, int y, int num, bool what) {
	check_row[x][num] = what;
	check_col[y][num] = what;
	check_block[coorToBlockCount(x, y)][num] = what;
}

bool check_range(int x, int y) {
	return 0 <= x && x < 9 && 0 <= y && y < 9;
}

bool go(int row, int col) {
	if (col == 9) {
		col = 0;
		row += 1;
		if (row == 9) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					cout << a[i][j];
				}
				cout << '\n';
			}
			return true;
		}
	}
	if (a[row][col] != 0) {
		return go(row, col + 1);
	}
	else {
		for (int k = 0; k < 2; k++) {
			int nRow = row + dRow[k];
			int nCol = col + dCol[k];
			if (!check_range(nRow, nCol)) {
				continue;
			}
			if (a[nRow][nCol] != 0) continue;
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (i == j) continue;
					if (check_domino[i][j]) continue;
					if (isValid(row, col, i) && isValid(nRow, nCol, j)) {
						a[row][col] = i;
						a[nRow][nCol] = j;
						check(row, col, i, true);
						check(nRow, nCol, j, true);
						check_domino[i][j] = true;
						check_domino[j][i] = true;
						if (go(row, col + 1)) {
							return true;
						}
						a[row][col] = 0;
						a[nRow][nCol] = 0;
						check(row, col, i, false);
						check(nRow, nCol, j, false);
						check_domino[i][j] = false;
						check_domino[j][i] = false;
					}
				}
			}
		}
	}
	return false;
}


int main() {
	int count = 1;
	while (1) {
		memset(check_row, false, sizeof(check_row));
		memset(check_col, false, sizeof(check_col));
		memset(check_block, false, sizeof(check_block));
		memset(check_domino, false, sizeof(check_domino));
		memset(a, 0, sizeof(a));
		int n;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			int U, V;
			string LU, LV;
			cin >> U >> LU >> V >> LV;
			check_domino[U][V] = true;
			check_domino[V][U] = true;
			pair<int, int> coor = stringToCoordinate(LU);
			int x = coor.first;
			int y = coor.second;
			check(x, y, U, true);
			a[x][y] = U;
			coor = stringToCoordinate(LV);
			x = coor.first;
			y = coor.second;
			check(x, y, V, true);
			a[x][y] = V;
		}
		for (int i = 1; i <= 9; i++) {
			string L;
			cin >> L;
			pair<int, int> coor = stringToCoordinate(L);
			int x = coor.first;
			int y = coor.second;
			check(x, y, i, true);
			a[x][y] = i;
		}
		cout << "Puzzle " << count << '\n';
		go(0, 0);
		count += 1;
	}
	return 0;
}