#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char op[11][11];
int answer[11];
bool isInitial = true;

void go(int index, int n) {
    if (!isInitial) return;
    if (index == n) {
        for (int i = 0; i < n; i++) {
            cout << answer[i] << " ";
        }
        cout << '\n';
        isInitial = false;
        return;
    }
    int start, end;
    if (op[index][index] == '+') {
        start = 1;
        end = 10;
    }
    else if (op[index][index] == '-') {
        start = -10;
        end = -1;
    }
    else if (op[index][index] == '0') {
        start = 0;
        end = 0;
    }
    for (int i = start; i <= end; i++) {
        answer[index] = i;
        int sum = 0;
        bool isValid = true;
        for (int j = index; j >= 0; j--) {
            sum += answer[j];
            if (sum > 0 && op[j][index] == '+') continue;
            else if (sum == 0 && op[j][index] == '0') continue;
            else if (sum < 0 && op[j][index] == '-') continue;
            isValid = false;
            break;
        }
        if (!isValid) continue;

        go(index + 1, n);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> op[i][j];
        }
    }
    go(0, n);

    return 0;
}