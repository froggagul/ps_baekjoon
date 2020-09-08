#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct jewel {
	int weight, price;
};
jewel jewels[300000];
int bags[300000];
bool compare(jewel a, jewel b)
{
	//for descending order replace with a.roll >b.roll
	if (a.weight == b.weight)
		return a.price < b.price;
	else
		return a.weight < b.weight;
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		jewels[i] = { m, v };
	}
	for (int i = 0; i < k; i++) {
		cin >> bags[i];
	}
	sort(bags, bags + k);
	sort(jewels, jewels + n, compare);

	long long sum = 0;
	priority_queue<int> pq;
	int i, j = 0;
	for (i = 0; i < k; i += 1) {
		while (j < n && jewels[j].weight <= bags[i]) {
			pq.push(jewels[j].price);
			j += 1;
		}

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum << '\n';
	return 0;
}