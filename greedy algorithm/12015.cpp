#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> res;
	for (int i = 0; i < n; i++) {
		int lo = lower_bound(res.begin(), res.end(), v[i]) - res.begin();
		if (lo == res.size()) {
			res.push_back(v[i]);
		}
		else {
			res[lo] = v[i];
		}
	}
	cout << res.size() << '\n';
	return 0;
}