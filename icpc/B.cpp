#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int divide = 16769023;
	int ans = 1;
	for (int i = 0; i < (n + 1) / 2; i++) {
		ans <<= 1;
		ans %= divide;
	}
	printf("%d\n", ans);
	return 0;
}