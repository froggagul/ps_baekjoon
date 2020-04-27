#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int d[100001][4] = { 0 };

int go(int exc, int n) {
    if (d[n][exc] > -1) return d[n][exc];
    for (int i = 1; i <= 3; i++) {
        if (i != exc && n - i >= 0) {
            d[n][exc] = (d[n][exc] + go(i, n - i)) % 1000000009;
        }
    }
    return d[n][exc];
}

int main()
{
    for (int i = 0; i < 100001; i++) {
        for (int j = 0; j < 4; j++) {
            d[i][j] = -1;//미정
        }
    }
    d[0][1] = 1;
    d[1][1] = 0;
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++) {
        int curr;
        cin >> curr;
        int result = go(0, curr);
        if (result == 0) {
            result = 1000000008;
        }
        else {
            result -= 1;
        }
        // 하나밖에 없는 경우
        cout << result << '\n';
    }
    return 0;
}