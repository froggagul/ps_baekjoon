#include <iostream>

using namespace std;

int coin[21];
int n, ans = 401;

void output(int a)
{
    if (a == n + 1)
    {
        int total = 0;
        for (int i = 1; i <= (1 << (n - 1)); i *= 2)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (coin[j] & i)
                    cnt++;
            }
            if (cnt < n - cnt) total += cnt;
            else total += n - cnt;
        }
        if (ans > total) ans = total;
    }
    else
    {
        coin[a] = ~coin[a];
        output(a + 1);
        coin[a] = ~coin[a];
        output(a + 1);
    }
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cur = 0;
		int indices = 1 <<(n - 1);
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == 'T') {
				cur = cur + indices;
			}
			indices >>= 1;
		}
		coin[i] = cur;
	}
    output(1);
    cout << ans << '\n';
	return 0;
}