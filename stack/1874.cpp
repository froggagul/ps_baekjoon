#include <iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(nullptr);
	int n;
	int current = 1;
	string record;
	cin >> n;
	stack<int> numbers;
	bool found;
	while (n--) {
		int num;
		cin >> num;
		if (current <= num) {
			while (current <= num) {
				numbers.push(current);
				record += '+';
				current += 1;
			}
			numbers.pop();
			record += '-';
		}
		else {
			found = false;
			if (!numbers.empty()) {
				int top = numbers.top();
				numbers.pop();
				record += '-';
				if (top == num) {
					found = true;
				}
			}
			if (!found) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	if (found) {
		for (int i = 0; i < record.size(); i++) {
			cout << record[i] << '\n';
		}
	}
	return 0;
}