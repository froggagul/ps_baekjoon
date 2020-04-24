#include <iostream>
using namespace std;
struct Queue {
	int data[10000];
	int begin, end;
	Queue() {
		begin = 0;
		end = 0;
	}
	int size() {
		return end - begin;
	}
	bool empty() {
		return end == begin;
	}
	void push(int num) {
		data[end] = num;
		end += 1;
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			begin += 1;
			return data[begin - 1];
		}
	}
	int front() {
		if (empty()) {
			return -1;
		}
		else {
			return data[begin];
		}
	}
	int back() {
		if (empty()) {
			return -1;
		}
		else {
			return data[end - 1];
		}
	}
};


int main() {
	int n;
	cin >> n;
	Queue queue;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int num;
			cin >> num;
			queue.push(num);
		}
		else if (cmd == "front") {
			cout << (queue.front()) << '\n';
		}
		else if (cmd == "back") {
			cout << (queue.back()) << '\n';
		}
		else if (cmd == "size") {
			cout << queue.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << (queue.empty() ? 1 : 0 ) << '\n';
		}
		else if (cmd == "pop") {
			cout << queue.pop() << '\n';
		}
	}
}