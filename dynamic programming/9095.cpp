#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int d[11] = { 0 };

int go(int n) {
    if (d[n] > 0) return d[n];
    d[n] = go(n - 1) + go(n - 2) + go(n - 3);
    return d[n];
}

int main()
{
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    int num;
    cin >> num;
    while (num--) {
        int q;
        cin >> q;
        cout << go(q) << '\n';
    }
    return 0;
}