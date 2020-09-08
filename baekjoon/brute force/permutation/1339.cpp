#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int index[26] = { 0 };

int go(vector<int>& temp, int n, vector<char>(&str)[10]) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int partSum = 0;
		for (int j = 0; j < str[i].size(); j++) {
			partSum = partSum * 10 + temp[index[str[i][j] - 'A']];
		}
		sum += partSum;
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	bool check[26] = { 0 };
	vector<char> q[10];
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			q[i].push_back(s[j]);
			if (!check[s[j] - 'A']) {
				check[s[j] - 'A'] = true;
				index[s[j] - 'A'] = cnt;
				cnt += 1;
			}
		}
	}
	int max = 0;
	vector<int> ans;
	for (int i = 0; i < cnt; i++) {
		ans.push_back(9 - i);
	}
	do
	{
		int temp = go(ans, n, q);
		if (temp > max) {
			max = temp;
		}
	} while (prev_permutation(ans.begin(), ans.end()));
	cout << max << '\n';
	return 0;
}