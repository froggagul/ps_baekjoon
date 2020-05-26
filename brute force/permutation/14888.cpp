#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long go(vector<int>& operands, vector<int>& operators) {
	long long result = operands[0];
	for (int i = 0; i < operators.size(); i++) {
		int op = operators[i];
		if (op == 1) {
			result += operands[i + 1];
		}
		else if (op == 2) {
			result -= operands[i + 1];
		}
		else if (op == 3) {
			result *= operands[i + 1];
		}
		else if (op == 4) {
			result /= operands[i + 1];
		}
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<int> operators;
	vector<int> operands(n);
	for (int i = 0; i < n; i++) {
		cin >> operands[i];
	}
	for (int i = 1; i <= 4; i++) {
		int temp;
		cin >> temp;
		for (int j = 1; j <= temp; j++) {
			operators.push_back(i);
		}
	}
	long long max = -1000000000;
	long long min = 1000000000;
	do {
		long long temp = go(operands, operators);
		if (temp > max) {
			max = temp;
		}
		if (temp < min) {
			min = temp;
		}
	} while (next_permutation(operators.begin(), operators.end()));
	cout << max << '\n';
	cout << min << '\n';
}