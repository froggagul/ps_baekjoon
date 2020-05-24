#include <iostream>
#include <vector>
#include<queue>;
using namespace std;

#define MAX 100001

int dist[MAX];
queue<int> q;

int main() {
	int start, end;
	cin >> start >> end;
	q.push(start);
	dist[start] = 1;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		if (curr == end) {
			cout << dist[curr] - 1 << '\n';
			return 0;
		}
		for (int i = 0; i < 3; i++) {
			int temp = -1;
			switch (i)
			{
			case 0: if (curr - 1 >= 0) temp = curr - 1; 
				break;
			case 1: if (curr + 1 <= MAX) temp = curr + 1; 
				break;
			case 2: if (curr * 2 <= MAX) temp = curr * 2; 
				break;
			default:
				break;
			}
			if (temp == -1 || dist[temp] > 0) continue;
			dist[temp] = dist[curr] + 1;
			q.push(temp);
		}
	}
	cout << -1 << '\n';
	return 0;
}