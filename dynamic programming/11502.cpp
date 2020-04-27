#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int d[1001] = { 0 };
int price[1001] = { 0 };

int go(int n) {
    if (n == 0) return 0;
    if (d[n] > 0) return d[n];
    int max = 0;
    for (int i = 1; i <= n; i++) {
        int temp = go(n - i) + price[i];
        if (temp > max) {
            max = temp;
        }
    }
    d[n] = max;
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