#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int q[1000] = { 0 };
int d[1000] = { 0 };

int main() {
	int num;
	cin >> num;
	num;
	for (int i = 0; i < num; i++) {
		int curr;
		cin >> curr;
		q[i] = curr;
	}
	for (int i = num - 1; i >= 0; i--) {
		d[i] = 1;
		for (int j = i; j < num; j++) {
			if (q[i] < q[j] && d[i] < (d[j] + 1)) {
				d[i] = d[j] + 1;
			}
		}
	}
	int max = 0;
	int startIndex = 0;
	for (int i = 0; i < num; i++) {
		int temp = d[i];
		if (temp > max) {
			max = temp;
			startIndex = i;
		}
	}
	cout << max << '\n';
	cout << q[startIndex] << " ";
	max -= 1;
	int lastIndex = startIndex;
	for (int i = startIndex + 1; i < num; i++) {
		int temp = d[i];
		if (temp == max && q[lastIndex] < q[i]) {
			cout << q[i] << " ";
			lastIndex = i;
			max -= 1;
		}
	}
	return 0;
}