#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long long d[101][10];
const long long mod = 1000000000LL;
const int limit = 100;
int main() {
    for (int j = 0; j <= 9; j++) {
        d[1][j] = 1;
    }
    for (int i = 2; i <= limit; i++) {
        d[i][0] = d[i - 1][1] % mod;
        for (int j = 1; j <= 8; j++) {
            d[i][j] = (d[i - 1][j + 1] + d[i - 1][j - 1]) % mod;
        }
        d[i][9] = d[i - 1][8] % mod;
    }
    int n;
    scanf("%d", &n);
    long long result = 0;
    for (int j = 1; j <= 9; j++) {
        result += d[n][j];
    }
    result %= mod;
    printf("%lld\n", result);
}