#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stack>
#include<string>
#include <cstring>
using namespace std;

char sentence[100000];
int main() {
	stack<char> left, right;
	scanf("%s", sentence);
	int size = strlen(sentence);
	for (int i = 0; i < size; i++) {
		left.push(sentence[i]);
	}
	int n;
	scanf("%d", &n);
	while (n--) {
		char cmd;
		scanf(" %c", &cmd);
		if (cmd == 'L') {
			if (!left.empty()) {
				char top = left.top();
				left.pop();
				right.push(top);
			}
		}
		else if (cmd == 'D') {
			if (!right.empty()) {
				char top = right.top();
				right.pop();
				left.push(top);
			}
		}
		else if (cmd == 'B') {
			if (!left.empty()) {
				left.pop();
			}
		}
		else if (cmd == 'P') {
			char character;
			scanf(" %c", &character);
			left.push(character);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		printf("%c", right.top());
		right.pop();
	}
	printf("\n");
	return 0;
}