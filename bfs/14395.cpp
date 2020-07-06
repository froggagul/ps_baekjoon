#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


struct node {
	long long num;
	string calc;
};
queue<node> q;

int main() {
	long long start, end;
	cin >> start >> end;
	if (start == end) {
		cout << 0 << '\n';
		return 0;
	}
	else if (end == 1) {
		cout << '/' << '\n';
		return 0;
	}
	string ans = "";
	q.push({ start, "" });
	while (!q.empty()) {
		node cur = q.front();
		long long n = cur.num;
		q.pop();
		if (n == end) {
			if (ans == "") {
				ans = cur.calc;
			}
			else {
				if (ans.size() > cur.calc.size()) {
					ans = cur.calc;
				}
				else if (ans.size() == cur.calc.size() && ans.compare(cur.calc) > 0) {
					ans = cur.calc;
				}
			}
		}
		int nl = cur.calc.size() + 1;
		if (1 >= nl) {
			q.push({ 1, cur.calc + '/' });
		}
		if (n * 2 <= end) {
			q.push({ n << 1, cur.calc + '+' });
		}
		if (n != 1 && n * n <= end) {
			q.push({ n * n, cur.calc + '*' });
		}
	}
	if (ans == "") {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}
	return 0;
}