#include<bits/stdc++.h>
using namespace std;

int p = 1000000007;

long long pow_mod(long long a, long long k) {
    long long ret;
    if (k == 0) return 1;
    long long n = pow_mod(a, k / 2);
    long long n2 = n * n % p;
    if (k & 1) {
        return a * n2 % p;
    } else {
        return n2;
    }
}


// nCk % mod의 값을 return
long long combination(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }

    long long res = 1;

    long long factorial_n = 1, factorial_inverse[3] = { 0 };
    for (int i = 2; i <= n; i++) {
        factorial_n = (factorial_n * i) % p;
    }

    factorial_inverse[0] = pow_mod(factorial_n, p - 2);

    for (int i = n - 1; i > 0; i--) {
        factorial_inverse[0] = (factorial_inverse[0] * (i + 1)) % p; // a!^-1 = (a + 1)!^-1 * (a+1)
        // k 는 0, n이 아님
        if (i == (n - k)) {
            factorial_inverse[1] = factorial_inverse[0];
        } else if (i == k) {
            factorial_inverse[2] = factorial_inverse[0];
        }
    }

    res = (factorial_n * factorial_inverse[1]) % p;
    res = (res * factorial_inverse[2]) % p;
    return res;
}

int main () {
    int n, k;
    cin >> n >> k;
    cout << combination(n, k) << '\n';
    return 0;
}
/** 
1. p=1000000007는 소수이다. 즉, a^p-1 = 1 mod p 이고 a ^ p-2는 a의 역원이 된다.
2. nCk를 재귀로 풀게 되면 시간 복잡도가 n^2이 된다. 따라서, nCk를 n! * (n-k)!^-1 * (k)!^-1 mod p로 구성하자.
3. 역원을 구하는 것은 a ^ p-2 mod p를 계산하는 것과 같으므로, 분할정복을 통해 시간복잡도를 줄여보자
4. 모든 항에 대해서 역원을 구하면 시간이 너무 오래걸리므로, n!^-1을 계산한 후 i!^-1 = (i + 1)!^-1 * (i + 1)을 이용해 구해보자
키포인트
* 큰수의 거듭제곱은 분할정복을 활용하자.
* 비슷한 항 끼리 일반식을 세워보려는 시도를 하자 
*/