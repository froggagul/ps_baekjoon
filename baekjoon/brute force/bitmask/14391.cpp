#include <iostream>
#include <vector>
#include <string>
using namespace std;
int question[16];

int bitToSum(int bit, int n, int m) {
	int result = 0;
	int curr = 0;
	bool check[16] = {0};
	for (int i = 0; i < m * n; i++) {
		if (check[i]) continue;
		if ((bit & (1 << i)) == 0) {
			for (int j = i; j < (i / m + 1) * m; j++) {
				if ((bit & (1 << j)) > 0) break;
				check[j] = true;
				curr = curr * 10 + question[j];
			}
			result += curr;
			curr = 0;
		}
		else {
			for (int j = i; j / m < n; j += m) {
				if ((bit & (1 << j)) == 0) break;
				check[j] = true;
				curr = curr * 10 + question[j];
			}
			result += curr;
			curr = 0;
		}
	}
	return result;
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			question[i * m + j] = temp[j] - '0';
		}
	}
	int ans = -1;
	for (int i = 0; i < (1 << m * n); i++) {
		int tempSum = bitToSum(i, n, m);
		if (ans == -1) {
			ans = tempSum;
		}
		else {
			if (ans < tempSum) {
				ans = tempSum;
			}
		}
	}
	cout << ans << '\n';
}