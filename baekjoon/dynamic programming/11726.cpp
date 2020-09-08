#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int d[1001] = { 0 };

int go(int n) {
    if (d[n] > 0) return d[n];
    d[n] = (go(n - 1) + go(n-2)) % 10007;
    return d[n];
}

int main()
{
    d[0] = 1;
    d[1] = 1;
    int num;
    cin >> num;
    cout << go(num) << '\n';
    return 0;
}