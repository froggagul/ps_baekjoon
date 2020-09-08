#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct schedule {
	int start, end;
};

bool compare(schedule a, schedule b) {
	if (a.end != b.end) {
		return a.end < b.end;
	}
	else {
		return a.start < b.start;
	}
}

int main() {
	int n;
	cin >> n;
	vector<schedule> v;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back({ start, end });
	}
	sort(v.begin(), v.end(), compare);
	int cnt = 1;
	schedule cur = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i].start >= cur.end) {
			cur = v[i];
			cnt += 1;
		}
	}
	cout << cnt << '\n';
	return 0;
}