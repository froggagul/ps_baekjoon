#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int length(int curr) {
	int len = 0;
	while (curr > 0) {
		curr /= 10;
		len += 1;
	}
	return len;
}

int main() {
	int num;
	cin >> num;
	long long count = 0;
	for (int i = 1; i <= num; i++) {
		count += length(i);
	}
	cout << count << '\n';
	return 0;
}