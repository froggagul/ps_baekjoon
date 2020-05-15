#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int prices[15][2] = { 0 };

int go(int currDay, int sum, int n) {
	if (currDay == n) return sum;
	if (currDay >= n) return 0;
	int yes = go(currDay + prices[currDay][0], sum + prices[currDay][1], n);
	int no = go(currDay + 1, sum, n);
	if (yes > no) {
		return yes;
	}
	return no;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> prices[i][0];	// 기간
		cin >> prices[i][1];	// 금액
	}
	int sum = go(0, 0, n);
	cout << sum << '\n';
	return 0;
}