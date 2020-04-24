#include <iostream>
using namespace std;

struct Stack {
	int data[10000];
	int size;
	Stack() {
		size = 0;
	}
	void push(int num) {
		data[size] = num;
		size += 1;
	}
	bool empty() {
		return size == 0;
	}
	int pop() {
		if (empty()) {
			return -1;
		} else {
			size -= 1;
			return data[size];
		}
	}
	int top() {
		if (empty()) {
			return -1;
		}
		else {
			return data[size - 1];
		}
	}
};
// 스택 직접 구현
int main() {
	int n;
	cin >> n;

	Stack stack;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int num;
			cin >> num;
			stack.push(num);
		}
		else if (cmd == "top") {
			cout << (stack.empty() ? -1 : stack.top() ) << '\n';
		}
		else if (cmd == "size") {
			cout << stack.size << '\n';
		}
		else if (cmd == "empty") {
			cout << stack.empty() << '\n';
		}
		else if (cmd == "pop") {
			cout << (stack.empty() ? -1 : stack.top() ) << '\n';
			if (!stack.empty()) {
				stack.pop();
			}
		}
	}
}