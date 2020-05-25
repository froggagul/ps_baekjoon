#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001
bool isUnderRoot[MAX];
int sons[MAX][2] = { 0 }; // A~Z : 0 ~ 25
int widths[MAX] = { 0 };
int levels[MAX] = { 0 };

int order(int root, int startWidth, int level) {
	int leftSize, rightSize;
	if (sons[root][0] == -1) {
		leftSize = 0;
	}
	else {
		leftSize = order(sons[root][0], startWidth, level + 1);
	}
	levels[root] = level;
	widths[root] = startWidth + leftSize + 1;
	if (sons[root][1] == -1) {
		rightSize = 0;
	}
	else {
		rightSize = order(sons[root][1], widths[root], level + 1);
	}
	return leftSize + rightSize + 1;
}

int main() {
	int n;
	cin >> n;
	int root;
	for (int i = 0; i < n; i++) {
		int p, s1, s2;
		cin >> p >> s1 >> s2;
		if (!isUnderRoot[s1]) {
			isUnderRoot[s1] = true;
		}
		if (!isUnderRoot[s2]) {
			isUnderRoot[s2] = true;
		}
		sons[p][0] = s1;
		sons[p][1] = s2;
	}
	for (int i = 1; i <= n; i++) {
		if (!isUnderRoot[i]) {
			order(i, 0, 1);
			break;
		}
	}
	int maxWidth = 0;
	int maxLevel = 1;
	vector<int> v[501];
	for (int i = 1; i <= n; i++) {
		int tempLevel = levels[i];
		if (v[tempLevel].size() == 2) {
			int start = v[tempLevel][0];
			int end = v[tempLevel][1];
			if (widths[start] > widths[i]) {
				v[tempLevel][0] = i;
				start = i;
			}
			if (widths[i] > widths[end]) {
				v[tempLevel][1] = i;
				end = i;
			}
			int tempWidth = widths[end] - widths[start];
			if (tempWidth > maxWidth) {
				maxWidth = tempWidth;
				maxLevel = tempLevel;
			}
			else if (tempWidth == maxWidth) {
				if (tempLevel < maxLevel) {
					maxWidth = tempWidth;
					maxLevel = tempLevel;
				}
			}
		}
		else if (v[tempLevel].size() == 0) {
			v[tempLevel].push_back(i);
			v[tempLevel].push_back(i);
		}
	}
	cout << maxLevel << " " << maxWidth + 1 << '\n';
	return 0;
}