#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
bool isPrime[10][10][10][10];
bool visit[10][10][10][10];

bool checkPrime(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
struct node {
	int i1, i2, i3, i4, cnt;
};
int main() {
	for (int i1 = 1; i1 < 10; i1++) {
		for (int i2 = 0; i2 < 10; i2++) {
			for (int i3 = 0; i3 < 10; i3++) {
				for (int i4 = 0; i4 < 10; i4++) {
					int num = i1 * 1000 + i2 * 100 + i3 * 10 + i4;
					if (checkPrime(num)) {
						isPrime[i1][i2][i3][i4] = true;
					}
				}
			}
		}
	}

	int n;
	cin >> n;
	while (n--) {
		int start, end;
		cin >> start >> end;
		queue<node> q;
		memset(visit, false, sizeof(visit));
		int i1 = start / 1000;
		start %= 1000;
		int i2 = start / 100;
		start %= 100;
		int i3 = start / 10;
		start %= 10;
		int i4 = start;
		q.push({ i1, i2, i3, i4, 0 });
		visit[i1][i2][i3][i4] = true;
		while (!q.empty()) {
			node cur = q.front();
			q.pop();
			int num = cur.i1 * 1000 + cur.i2 * 100 + cur.i3 * 10 + cur.i4;
			if (end == num) {
				cout << cur.cnt << '\n';
				break;
			}
			for (int j = 0; j < 10; j++) {
				if (j != 0) {
					if (isPrime[j][cur.i2][cur.i3][cur.i4] && !visit[j][cur.i2][cur.i3][cur.i4]) {
						q.push({ j, cur.i2, cur.i3, cur.i4, cur.cnt + 1 });
						visit[j][cur.i2][cur.i3][cur.i4] = true;
					}
				}
				if (isPrime[cur.i1][j][cur.i3][cur.i4] && !visit[cur.i1][j][cur.i3][cur.i4]) {
					q.push({ cur.i1, j, cur.i3, cur.i4, cur.cnt + 1 });
					visit[cur.i1][j][cur.i3][cur.i4] = true;
				}
				if (isPrime[cur.i1][cur.i2][j][cur.i4] && !visit[cur.i1][cur.i2][j][cur.i4]) {
					q.push({ cur.i1, cur.i2, j, cur.i4, cur.cnt + 1 });
					visit[cur.i1][cur.i2][j][cur.i4] = true;
				}
				if (isPrime[cur.i1][cur.i2][cur.i3][j] && !visit[cur.i1][cur.i2][cur.i3][j]) {
					q.push({ cur.i1, cur.i2, cur.i3, j, cur.cnt + 1 });
					visit[cur.i1][cur.i2][cur.i3][j] = true;
				}
			}
		}
	}
	return 0;
}