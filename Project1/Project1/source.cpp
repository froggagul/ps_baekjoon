#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int num;
	cin >> num;
	while (num -- ) {
		int m, n, x, y;
		cin >> m;
		cin >> n;
		cin >> x;
		cin >> y;
		x -= 1;
		y -= 1;

		int tempx = 0;
		int tempy = 0;
		int answer = -1;
		for (int i = x; i < m * n; i += m) {
			tempx = i % m;
			tempy = i % n;
			if (tempx == x && tempy == y) {
				answer = i + 1;
				break;
			}
		}
		if (answer != -1) {
			cout << answer << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
	return 0;
}