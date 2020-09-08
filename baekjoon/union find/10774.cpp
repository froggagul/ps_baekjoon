#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int J, P;
	cin >> J >> P;
	vector<char> arr(J + 1);
	for (int i = 0; i < J; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	for (int i = 0; i < P; i++) {
		char size;
		int num;
		cin >> size >> num;
		num -= 1;
		if (size == 'L') {
			if (arr[num] == 'L') {
				arr[num] = 0;
				cnt += 1;
			}
		}
		else if (size == 'M') {
			if (arr[num] == 'L' || arr[num] == 'M') {
				arr[num] = 0;
				cnt += 1;
			}
		}
		else if (size == 'S') {
			if (arr[num] == 'L' || arr[num] == 'M' || arr[num] == 'S') {
				arr[num] = 0;
				cnt += 1;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}