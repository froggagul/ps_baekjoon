#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define MAX 200002

bool visit[MAX];
queue<pair<int,int>> q;	//현재 위치, 시간

int main() {
	int start, end;
	cin >> start >> end;
	q.push({ start, 0 });
	visit[start] = true;
	while (!q.empty()) {
		int curr = q.front().first;
		int time = q.front().second;
		q.pop();
		if (curr == end) {
			cout << time << '\n';
			return 0;
		}
		if (curr - 1 >= 0) {
			if (!visit[curr - 1]) {
				visit[curr - 1] = true;
				q.push({ curr - 1, time + 1 });
			}
			for (int i = curr; i < end * 2; i *= 2) {
				if (!visit[i]) {
					visit[i] = true;
					q.push({ i, time });
				}
			}
		}
		if (curr + 1 < MAX) {
			if (!visit[curr + 1]) {
				visit[curr + 1] = true;
				q.push({ curr + 1, time + 1 });
			}
		}
	}
	cout << -1 << '\n';
	return 0;
}