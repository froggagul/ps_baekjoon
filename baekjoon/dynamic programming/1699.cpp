#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
using namespace std;
int d[100001] = { 0 };

int main() {
	int num;
	cin >> num;
	num;
	for (int i = 1; i <= sqrt(num); i++) {
		d[i * i] = 1;
	}
	for (int i = 1; i <= num; i++) {
		if (d[i] != 1) {
			d[i] = d[1] + d[i - 1];
			for (int j = 2; j <= i / 2; j++) {
				int temp = d[j] + d[i - j];
				if (d[i] > temp) {
					d[i] = temp;
				}
			}
		}
	}
	cout << d[num] << '\n';
	return 0;
}