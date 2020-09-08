#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int question[3] = { 0 };
	cin >> question[0];
	cin >> question[1];
	cin >> question[2];
	int temp[3] = { 0 };
	for (int i = 1; i <= 7980; i++) {
		if (temp[0] == 15) {
			temp[0] = 1;
		}
		else {
			temp[0] += 1;
		}
		if (temp[1] == 28) {
			temp[1] = 1;
		}
		else {
			temp[1] += 1;
		}
		if (temp[2] == 19) {
			temp[2] = 1;
		}
		else {
			temp[2] += 1;
		}
		if (question[0] == temp[0] && question[1] == temp[1] && question[2] == temp[2]) {
			cout << i << '\n';
			return 0;
		}
	}
	return 0;
}