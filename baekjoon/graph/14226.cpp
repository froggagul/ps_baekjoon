#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define MAX 2000

bool visit[MAX][MAX];
queue<pair<pair<int,int>, int>> q;

int main() {
	int end;
	cin >> end;
	q.push({ { 1, 0 }, 0 });
	while (!q.empty()) {
		int curr = q.front().first.first;	//화면
		int clip = q.front().first.second; //클립보드
		int t = q.front().second;
		q.pop();
		if (curr == end) {
			cout << t << '\n';
			return 0;
		}
		if (curr > 0 && curr < MAX) {
			if (!visit[curr][curr]) {
				visit[curr][curr] = true;
				q.push({ { curr, curr }, t + 1});
			}
			if (!visit[curr - 1][curr]) {
				visit[curr][curr] = true;
				q.push({ { curr - 1, clip }, t + 1 });
			}
		}
		if (clip > 0 && curr + clip < MAX) {
			if (!visit[curr + clip][clip]) {
				visit[curr + clip][clip] = true;
				q.push({{curr + clip, clip}, t + 1});
			}
		}
	}
	cout << -1 << '\n';
	return 0;
}