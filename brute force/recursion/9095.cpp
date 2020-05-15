#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int go(int sum, int goal) {
	if (sum > goal) return 0;   // 합이 goal보다 넘어버리면, 더하는 의미가 없어지므로, 카운팅하지 않는다.
	if (sum == goal) return 1;
	int now = 0;
	for (int i = 1; i <= 3; i++) {
		now += go(sum + i, goal);
	}
	return now;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		int curr;
		cin >> curr;
		cout << go(0, curr) << '\n';
	}
	return 0;
}