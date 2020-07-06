#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<bool> start1(n);
	vector<bool> start2(n);
	vector<bool> end(n);
	string str;
	cin >> str;
	for (int i = 0; i < n; i++) {
		start1[i] = str[i] - '0';
		start2[i] = start1[i];
	}
	cin >> str;
	for (int i = 0; i < n; i++) {
		end[i] = str[i] - '0';
	}
	// 0번째에서 변환 없을때
	int cnt = 0;
	int cnt2 = 1;
	start2[0] = !start2[0];
	start2[1] = !start2[1];
	for (int i = 1; i < n; i++) {
		if (end[i - 1] != start1[i - 1]) {
			for (int j = -1; j <= 1; j++) {
				if (i + j < n) {
					start1[i + j] = !start1[i + j];
				}
			}
			cnt += 1;
		}
		if (end[i - 1] != start2[i - 1]) {
			for (int j = -1; j <= 1; j++) {
				if (i + j < n) {
					start2[i + j] = !start2[i + j];
				}
			}
			cnt2 += 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (end[i] != start1[i]) {
			cnt = -1;
		}
		if (end[i] != start2[i]) {
			cnt2 = -1;
		}
	}
	int ans = cnt;
	if (ans == -1) {
		ans = cnt2;
	}
	else {
		if (cnt2 != -1 && cnt > cnt2) {
			ans = cnt2;
		}
	}
	cout << ans << '\n';
	return 0;
}