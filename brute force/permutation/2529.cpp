#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool check(vector<int>& temp, vector<char> &relations) {
	for (int i = 0; i < relations.size(); i++) {
		if (relations[i] == '<' && temp[i] > temp[i + 1]) {
			return false;
		}
		else if (relations[i] == '>' && temp[i] < temp[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;

	vector<int> big, small;
	cin >> n;
	vector<char> relationShip(n);
	int i;
	for (i = 0; i < n; i++) {
		cin >> relationShip[i];
		small.push_back(i);
		big.push_back(9 - i);
	}
	small.push_back(i);
	big.push_back(9 - i);
	do
	{
		if (check(small, relationShip)) {
			break;
		}
	} while (next_permutation(small.begin(), small.end()));
	do
	{
		if (check(big, relationShip)) {
			break;
		}
	} while (prev_permutation(big.begin(), big.end()));
	for (i = 0; i < big.size(); i++) {
		cout << big[i];
	}
	cout << '\n';
	for (i = 0; i < small.size(); i++) {
		cout << small[i];
	}
	cout << '\n';
	return 0;
}