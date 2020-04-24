#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<queue>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	int j = 0;
	printf("<");
	while (!q.empty()) {
		if ((j + 1) % m == 0) {
			if (q.size() == 1) {
				printf("%d", q.front());
			}
			else {
				printf("%d, ", q.front());
			}
		}
		else {
			q.push(q.front());
		}
		q.pop();
		j += 1;
	}
	printf(">");
	return 0;
}