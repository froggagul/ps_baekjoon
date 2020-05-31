#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans = 0;
int n;

bool a[15][15] = { 0 };
bool check_col[15] = { 0 };
bool check_leftTop[29] = { 0 };
bool check_rightTop[29] = { 0 };


bool check(int row, int col) {
	if (check_col[col]) return false;
	if (check_leftTop[col - row + n - 1]) return false;
	if (check_rightTop[row + col]) return false;
	return true;
}

void calc(int row) {
	if (row == n) {
		ans += 1;
	}
	for (int col = 0; col < n; col++) {
		a[row][col] = true;
		if (check(row, col)) {
			check_col[col] = true;
			check_leftTop[col - row + n - 1] = true;
			check_rightTop[row + col] = true;
			calc(row + 1);
			check_col[col] = false;
			check_leftTop[col - row + n - 1] = false;
			check_rightTop[row + col] = false;
		}
		a[row][col] = false;
	}
	return;
}

int main() {
	cin >> n;
	calc(0);
	cout << ans << '\n';
}