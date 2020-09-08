#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	s += '\0';
	int result = 0;
	bool minus = false;
	string temp = "";
	for (char c : s) {
		if (c == '+' || c == '-' || c == '\0') {
			if (minus) {
				result -= stoi(temp);
			}
			else {
				result += stoi(temp);
			}
			temp = "";
			if (c == '-') {
				minus = true;
			}
		}
		else {
			temp += c;
		}
	}
	cout << result << '\n';
	return 0;
}