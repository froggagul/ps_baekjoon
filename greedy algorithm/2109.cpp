#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> lectures[10001];	//제한일수, 금액

int main() {
	int n, d = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lectures[i].second >> lectures[i].first;
	}
	sort(lectures, lectures + n);
	int sum = 0;
	int index = n - 1;
	priority_queue<int> pq;
	for (int i = lectures[n - 1].first; i >= 1; i--) {
		while (index < n && i <= lectures[index].first) {
			pq.push(lectures[index--].second);
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum << '\n';
	return 0;
}