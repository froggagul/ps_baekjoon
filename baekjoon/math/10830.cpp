#include <bits/stdc++.h>
using namespace std;

int mod = 1000;

int N;
long long B;

// A * B 계산
vector<vector<int>> mul_vec(vector<vector<int>> A, vector<vector<int>> B) {
    vector<vector<int>> res(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                res[i][j] += A[i][k] * B[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

// A^k를 계산
vector<vector<int>> pow_vec(vector<vector<int>> A, long long k) {
    if (k == 1) return A;

    vector<vector<int>> n = pow_vec(A, k/2);
    n = mul_vec(n, n);
    if (k & 1) {
        // k가 홀수
        return mul_vec(A, n);
    } else {
        // k가 짝수
        return n;
    }
}

int main() {
    cin >> N >> B;
    vector<vector<int>> A(N, vector<int>(N, 0));
    vector<vector<int>> ans(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    ans = pow_vec(A, B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] % mod << " ";
        }
        cout << "\n";
    }

    return 0;
}
/**
 * 1. B의 범위가 long long이다, A^B를 계산하기 위해서는 분할정복을 수행해야 한다.
2. 다만 A가 행렬이므로, 행렬을 계산하는 mul_vec을 사용한다.
3. 이를 제외하면 큰 수의 제곱과 같은 포맷
핵심
* 큰수의 거듭제곱은 분할정복을 활용하자.
실수
* input의 수 범위를 주시하자. long long이 필요한지, int가 필요한지 판단할 것
* 모든 행에 대해 mod가 제대로 적용됐는지 확인하기.
행렬 원소가 1000보다 작거나 같은 자연수라서 

2 1
1000 1000
1000 1000

입력이 위와 같으면

0 0
0 0

이 나와야하는데

1000 1000
1000 1000

이 결과로 나와요.
 * 
 * /
*/