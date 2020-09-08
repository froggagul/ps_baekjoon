#include <iostream>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

#define MAX 101
char sons[26][2] = { 0 }; // A~Z : 0 ~ 25

void preOrder(char root) {
	cout << root;
	for (int i = 0; i < 2; i++) {
		if (sons[root - 'A'][i] != '.') {
			preOrder(sons[root - 'A'][i]);
		}
	}
	return;
}

void inOrder(char root) {
	if (sons[root - 'A'][0] != '.') {
		inOrder(sons[root - 'A'][0]);
	}
	cout << root;
	if (sons[root - 'A'][1] != '.') {
		inOrder(sons[root - 'A'][1]);
	}
	return;
}

void postOrder(char root) {
	for (int i = 0; i < 2; i++) {
		if (sons[root - 'A'][i] != '.') {
			postOrder(sons[root - 'A'][i]);
		}
	}
	cout << root;
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char p, s1, s2;
		cin >> p >> s1 >> s2;
		sons[p - 'A'][0] = s1;
		sons[p - 'A'][1] = s2;
	}
	preOrder('A');
	cout << '\n';
	inOrder('A');
	cout << '\n';
	postOrder('A');
	cout << '\n';
	return 0;
}