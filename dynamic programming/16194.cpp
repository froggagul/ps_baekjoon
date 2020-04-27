#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int d[1001] = { 0 };
int price[1001] = { 0 };

int go(int n) {
    if (n == 0) return 0;
    if (d[n] > 0) return d[n];
    int min = go(n - 1) + price[1]; //min을 0으로 놓으면 현 알고리즘에서는 비교 불가
    for (int i = 2; i <= n; i++) {
        int temp = go(n - i) + price[i];
        if (temp < min) {
            min = temp;
        }
    }
    d[n] = min;
    return d[n];
}

int main()
{
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++) {
        int curr;
        cin >> curr;
        price[i] = curr;
    }
    d[1] = price[1];
    cout << go(num) << '\n';
    return 0;
}