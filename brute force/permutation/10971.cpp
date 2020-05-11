#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int result = 0;
int answers[10];	// 지역 방문 순서
bool checks[10];	// 해당 지역을 방문했는가?
int cost[10][10] = { 0 };	// 드는 비용

int absolute(int a, int b) {
	int result = a - b;
	if (result > 0) return result;
	else return -result;
}


void go(int index, int n) {
	if (index == n) {
		int temp = 0;
		if (cost[answers[n - 1]][answers[0]] == 0) return;
		temp += cost[answers[n - 1]][answers[0]];
		for (int i = 0; i < n - 1; i++) {
			temp += cost[answers[i]][answers[i + 1]];
		}
		if (temp < result || result == 0) result = temp;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (checks[i] || cost[answers[index - 1]][i] == 0) continue;
		checks[i] = true;
		answers[index] = i;
		go(index + 1, n);
		checks[i] = false;
	}
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
		checks[i] = false;
	}
	go(0, n);
	cout << result << '\n';
	return 0;
}