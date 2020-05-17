#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, sum;
    cin >> n;
    cin >> sum;
    int numbers[20];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int count = 0;
    for (int i = 1; i < (1 << n); i++) {
        int tempSum = 0;
        for (int k = 0; k < n; k++) {
            if (i & (1 << k)) {
                tempSum += numbers[k];
            }
        }
        if (sum == tempSum) {
            count += 1;
        }
    }
    cout << count << '\n';
    return 0;
}