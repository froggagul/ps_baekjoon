#include<bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int curr;
	priority_queue<int> smaller;
	priority_queue<int> bigger;
	for (int i = 0; i < n; i++) {
		cin >> curr;
		if ((i&1) == 0) {
			smaller.push(curr);
		}
		else {
			bigger.push(-curr);
		}
		if (!smaller.empty() && !bigger.empty()) {
			int smaller_top = smaller.top();
			int bigger_top = -bigger.top();
			if (smaller_top > bigger_top) {
				smaller.pop();
				bigger.pop();
				smaller.push(bigger_top);
				bigger.push(-smaller_top);
			}

		}
		cout << smaller.top() << '\n';
	}
	return 0;
}