#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[20];
bool check[20 * 100000 + 1];
int n;

void go(int index, int sum) {
	if (index == n) {
		if (!check[sum]) {
			check[sum] = true;
		}
		return;
	}
	go(index + 1, sum);
	go(index + 1, sum + a[index]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	go(0, 0);
	for (int i = 1;; i++) {
		if (!check[i]) {
			cout << i << '\n';
			return 0;
		}
	}
	return 0;
}