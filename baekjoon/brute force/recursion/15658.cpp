#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

pair<int, int> calc(vector<int> &a, int index, int cur, int add, int sub, int mul, int div) {
	int n = a.size();
	if (index == n) {
		return make_pair(cur, cur);
	}
	vector<pair<int, int>> res;
    if (add > 0) {
        res.push_back(calc(a, index + 1, cur + a[index], add - 1, sub, mul, div));
    }
    if (sub > 0) {
        res.push_back(calc(a, index + 1, cur - a[index], add, sub - 1, mul, div));
    }
    if (mul > 0) {
        res.push_back(calc(a, index + 1, cur * a[index], add, sub, mul - 1, div));
    }
    if (div > 0) {
        res.push_back(calc(a, index + 1, cur / a[index], add, sub, mul, div - 1));
    }
    auto ans = res[0];
    for (auto p : res) {
        if (ans.first < p.first) {
            ans.first = p.first;
        }
        if (ans.second > p.second) {
            ans.second = p.second;
        }
    }
    return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int add, sub, mul, div;
	cin >> add >> sub >> mul >> div;
	auto p = calc(a, 1, a[0], add, sub, mul, div);
	cout << p.first << '\n';
	cout << p.second << '\n';
	return 0;

	return 0;
}