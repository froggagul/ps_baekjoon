#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int d[31][3] = { 0 };
//d[n][0] : 세개가 모두 가로로 되있는 상태에서 시작
//d[n][1] : ㄴ을 위로 뒤집은 모양으로 시작
//d[n][2] : ㄴ모양으로 시작

int main() {
	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << 0 << '\n';
	}
	else {//n이 짝수일때
		for (int i = 2; i <= n; i += 2) {
			if (i == 2) {
				for (int j = 0; j < 3; j++) {
					d[i][j] = 1;
				}
			}
			else {
				int add = 0;
				for (int j = 0; j < 3; j++) {
					add += d[i - 2][j];
				}
				d[i][0] = add;
				d[i][1] = add + d[i - 2][1];
				d[i][2] = add + d[i - 2][2];
			}
		}
		cout << d[n][0] + d[n][1] + d[n][2] << '\n';
	}
	return 0;
}