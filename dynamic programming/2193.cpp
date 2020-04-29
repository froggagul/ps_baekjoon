#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long long d[91] = {0};
int main() {
	d[1] = 1;
	for (int i = 2; i <= 90; i++) {
		if (i >= 3) {
			for (int j = 1; j <= i - 2; j++) {
				d[i] += d[j];
			}
		}
		d[i] += 1;
	}
    // 10으로 시작해 1이 나오기까지를 기준으로 점화식을 세웠다.
	int num;
	scanf("%d", &num);
	printf("%lld", d[num]);
	return 0;
}