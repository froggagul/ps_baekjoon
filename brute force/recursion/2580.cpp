#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[9][9] = { 0 };
bool rowCheck[9][10] = { 0 };
bool colCheck[9][10] = { 0 };
bool blockCheck[9][10] = { 0 };

bool isFound = false;

bool check(int row, int col, int block, int num) {
	if (rowCheck[row][num]) return false;
	if (colCheck[col][num]) return false;
	if (blockCheck[block][num]) return false;
	return true;
}

void go(int row, int col) {
	if (col == 9) {
		col = 0;
		row += 1;
		if (row == 9) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					cout << a[i][j] << " ";
				}
				cout << '\n';
			}
			isFound = true;
			return;
		}
	}
	int curr = a[row][col];
	if (curr == 0) {
		int x = row / 3;
		int y = col / 3;
		int block = y * 3 + x;
		for (int k = 1; k <= 9; k++) {
			if (check(row, col, block, k)) {
				a[row][col] = k;
				rowCheck[row][k] = true;
				colCheck[col][k] = true;
				blockCheck[block][k] = true;
				go(row, col + 1);
				if (isFound) return;
				a[row][col] = 0;
				rowCheck[row][k] = false;
				colCheck[col][k] = false;
				blockCheck[block][k] = false;
			}
		}
	}
	else {
		go(row, col + 1);
	}
	return;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a[i][j];
			int x = i / 3;
			int y = j / 3;
			int num = a[i][j];
			if (num > 0) {
				blockCheck[y * 3 + x][num] = true;
				rowCheck[i][num] = true;
				colCheck[j][num] = true;
			}
		}
	}
	cout << '\n';
	go(0, 0);
	
}