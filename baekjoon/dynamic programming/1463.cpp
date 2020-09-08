#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int d[1000000] = { 0 };

int go(int n) {
    if (n == 1) return 0;
    if (d[n] > 0) return d[n];
    d[n] = go(n - 1) + 1;
    if (n % 2 == 0) {
        int temp = go(n / 2) + 1;
        if(d[n] > temp) d[n] = temp;
    }
    if (n % 3 == 0) {
        int temp = go(n / 3) + 1;
        if (d[n] > temp) d[n] = temp;
    }
    return d[n];
}

int main()
{
    int num;
    cin >> num;
    cout << go(num) << '\n';
    return 0;
}