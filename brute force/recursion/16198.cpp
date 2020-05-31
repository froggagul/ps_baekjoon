#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans = 0;

void go(vector<int>& a, vector<bool>& check, int curr, int size, int n) {
	if (size == 2) {
		if (ans < curr) ans = curr;
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		if (check[i]) continue;
		int prevNum = 0, nextNum = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (!check[j]) {
				prevNum = j;
				break;
			}
		}
		for (int j = i + 1; j < n; j++) {
			if (!check[j]) {
				nextNum = j;
				break;
			}
		}
		check[i] = true;
		go(a, check, curr + a[prevNum] * a[nextNum], size - 1, n);
		check[i] = false;
	}
	return;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<bool> check(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	go(a, check, 0, n, n);
	cout << ans << '\n';
}