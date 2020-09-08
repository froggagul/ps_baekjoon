#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<vector<int>> question, int row, int col) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i + 1 < row && j + 1 < col) {
				int temp = question[i][j] + question[i + 1][j] + question[i][j + 1] + question[i + 1][j + 1];
				if (temp > sum) sum = temp;
			}	// 정사각형
			if (i + 3 < row) {
				int temp = question[i][j] + question[i + 1][j] + question[i + 2][j] + question[i + 3][j];
				if (temp > sum) sum = temp;
			}	// 1자 세로
			if (j + 3 < col) {
				int temp = question[i][j] + question[i][j + 1] + question[i][j + 2] + question[i][j + 3];
				if (temp > sum) sum = temp;
			}	// 1자 가로
			if (i + 2 < row && j + 1 < col) {
				int emptySum = question[i][j] + question[i + 1][j];
				for (int k = 0; k < 2; k++) {
					for (int m = 0; m < 2; m++) {
						if (emptySum > question[i + k][j + m] + question[i + k + 1][j + m]) {
							emptySum = question[i + k][j + m] + question[i + k + 1][j + m];
						}
					}
				}
				int temp = question[i][j] + question[i + 1][j] + question[i + 2][j] + question[i][j + 1] + question[i + 1][j + 1] + question[i + 2][j + 1] - emptySum;
				if (temp > sum) sum = temp;
			}	// ㄴ자 세로
			if (i + 1 < row && j + 2 < col) {
				int emptySum = question[i][j] + question[i][j + 1];
				for (int k = 0; k < 2; k++) {
					for (int m = 0; m < 2; m++) {
						if (emptySum > question[i + k][j + m] + question[i + k][j + m + 1]) {
							emptySum = question[i + k][j + m] + question[i + k][j + m + 1];
						}
					}
				}
				int temp = question[i][j] + question[i + 1][j] + question[i][j + 1] + question[i + 1][j + 1] + question[i][j + 2] + question[i + 1][j + 2] - emptySum;
				if (temp > sum) sum = temp;
			}	// ㄴ자 가로
			if (i - 1 >= 0 && j + 2 < col) {
				int temp = question[i][j] + question[i][j + 1] + question[i - 1][j + 1] + question[i - 1][j + 2];
				if (temp > sum) sum = temp;
			}
			if (i + 2 < row && j + 1 < col) {
				int temp = question[i][j] + question[i + 1][j] + question[i + 1][j + 1] + question[i + 2][j + 1];
				if (temp > sum) sum = temp;
			}
			if (i + 1 < row && j + 2 < col) {
				int temp = question[i][j] + question[i][j + 1] + question[i + 1][j + 1] + question[i + 1][j + 2];
				if (temp > sum) sum = temp;
			}
			if (i + 2 < row && j - 1 >= 0) {
				int temp = question[i][j] + question[i + 1][j] + question[i + 1][j - 1] + question[i + 2][j - 1];
				if (temp > sum) sum = temp;
			}
			if (j + 2 < col) {
				int temp = question[i][j] + question[i][j + 1] + question[i][j + 2];
				if (i - 1 >= 0) {
					int temp2 = temp + question[i - 1][j + 1];
					if (temp2 > sum) sum = temp2;
				}
				if (i + 1 < row) {
					int temp2 = temp + question[i + 1][j + 1];
					if (temp2 > sum) sum = temp2;
				}
			}
			if (i + 2 < row) {
				int temp = question[i][j] + question[i + 1][j] + question[i + 2][j];
				if (j + 1 < col) {
					int temp2 = temp + question[i + 1][j + 1];
					if (temp2 > sum) sum = temp2;
				}
				if (j - 1 >= 0) {
					int temp2 = temp + question[i + 1][j - 1];
					if (temp2 > sum) sum = temp2;
				}
			}
		}
	}
	return sum;
}

int main() {
	int row, col;
	cin >> row;
	cin >> col;
	vector<vector<int>> question(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> question[i][j];
		}
	}
	int answer = solve(question, row, col);
	cout << answer << '\n';
	return 0;
}