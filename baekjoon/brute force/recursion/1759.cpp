#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

char alphabets[15];
int answers[15];
int L, C;

void go(int index, int prev, int vowelCount) {
	if (L - index > C - prev) return;
	if (index == L) {
		if (vowelCount >= 1 && L - vowelCount >= 2) {
			for (int i = 0; i < L; i++) {
				cout << alphabets[answers[i]];
			}
			cout << '\n';
		}
		return;
	}
	for (int i = prev + 1; i < C; i++) {
		answers[index] = i;
		if (alphabets[i] == 'a' || alphabets[i] == 'e' || alphabets[i] == 'i' || alphabets[i] == 'o' || alphabets[i] == 'u') {
			go(index + 1, i, vowelCount + 1);
		}
		else {
			go(index + 1, i, vowelCount);
		}
	}
	return;
}
int main() {
	cin >> L;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> alphabets[i];
	}
	sort(alphabets, alphabets + C);
	go(0, -1, 0);
	return 0;
}