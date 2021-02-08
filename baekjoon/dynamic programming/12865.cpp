#include<bits/stdc++.h>
// typedef pair<int, int> pii;
using namespace std;
int dp[101][100001];

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> things(N);
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		things[i] = make_pair(a, b);
	}

	for (int i = 1; i <= N; i++) {
		int weight = things[i - 1].first;
		int value = things[i - 1].second;
		for (int j = 0; j <= K; j++) {
			if (weight <= j) {
				dp[i][j] = max(dp[i - 1][j - weight] + value, dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= K; i++) {
		if (ans < dp[N][i]) {
			ans = dp[N][i];
		}
	}
	cout << ans << '\n';
	return 0;
}