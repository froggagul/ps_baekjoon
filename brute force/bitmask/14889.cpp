#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int op[20][20] = { 0 };

bool isValid(int curr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if ((curr & (1 << i)) > 0) count += 1;
    }
    if (count * 2 == n) return true;
    return false;
}

int bitToScore(int bit, int n) {
    vector<int> first, second;
    for (int j = 0; j < n; j++) {
        if (bit & (1 << j)) {
            first.push_back(j);
        }
        else {
            second.push_back(j);
        }
    }
    int score = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            score += op[first[i]][first[j]];
            score -= op[second[i]][second[j]];
        }
    }
    if (score > 0) return score;
    return -score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> op[i][j];
        }
    }
    int ans = -1;
    for (int i = 1; i < (1 << n); i++) {
        if (isValid(i, n)) {
            int tempScore = bitToScore(i, n);
            if (ans == -1) {
                ans = tempScore;
            }
            else {
                if (ans > tempScore) {
                    ans = tempScore;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}