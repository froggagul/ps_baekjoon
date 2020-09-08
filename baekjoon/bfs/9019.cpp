#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

char calcs[4] = { 'D', 'S', 'L', 'R' };

int calc(char cmd, int num) {
	if (cmd == 'L') {
		num = num / 1000 + (num % 1000) * 10;
		return num;
	}
	else if (cmd == 'R') {
		num = num / 10 + (num % 10) * 1000;
		return num;
	}
	else if (cmd == 'S') {
		num -= 1;
		if (num == -1) return 9999;
		return num;
	}
	else if (cmd == 'D') {
		num *= 2;
		return num % 10000;
	}
	return -1;
}

int main() {
	int num;
	cin >> num;
	while (num--) {
		pair<char, int> visit[10000] = { make_pair(0, 0) };
		int start, end;
		cin >> start >> end;
		queue<int> q;
		q.push(start);
		visit[start] = make_pair(-1, -1);
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int temp = calc(calcs[i], curr);
				if (visit[temp].first == 0 && temp != -1) {
					visit[temp] = make_pair(calcs[i], curr);
					q.push(temp);
				}
			}
		}
		stack<char> s;
		int curr = end;
		while (true) {
			if (visit[curr].second == -1) break;
			s.push(visit[curr].first);
			curr = visit[curr].second;
		}
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		cout << '\n';
	}
	return 0;
}