#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int q[100001][3] = { 0 }; //d[i][j] : i번째 스티커를 뜯지 않았거나(j=0), 뜯었을때(위는 j=1 아래는 j=2) 점수 최댓값
int d[100001][3] = { 0 };
int main() {
	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= num; j++) {
				int temp;
				cin >> temp;
				q[j][i] = temp;
			}
		}
		for (int i = 0; i < 3; i++) {
			d[num][i] = q[num][i];
		}
		for (int i = num - 1; i >= 1; i--) {
			int case1 = d[i + 1][0];
			int case2 = d[i + 1][1];
			int case3 = d[i + 1][2];
			d[i][0] = case2 > case3 ? case2 : case3;
			d[i][1] = case1 > case3 ? case1 + q[i][1] : case3 + q[i][1];
			d[i][2] = case1 > case2 ? case1 + q[i][2] : case2 + q[i][2];
		}
		int result = 0;
		for (int i = 0; i < 3; i++) {
			result = result > d[1][i] ? result : d[1][i];
		}
		cout << result << '\n';
	}
	return 0;
}