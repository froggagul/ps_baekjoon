#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<stack>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    char regex[100] = {0};
    scanf("%s", regex);
    stack<double> nums;
    int var[26] = {0};
    for (int i = 0; i < n; i++) {
        int curr;
        scanf("%d", &curr);
        var[i] = curr;
    }
    int len = strlen(regex);
    for (int i = 0; i < len; i++) {
        char ch = regex[i];
        if (ch >= 'A' && ch <= 'Z') {
            nums.push((double)var[ch - 'A']);
        }
        else {
            double y = nums.top();
            nums.pop();
            double x = nums.top();
            nums.pop();
            double res = 0;
            switch (ch)
            {
            case '+':
                res = x + y;
                break;
            case '-':
                res = x - y;
                break;
            case '*':
                res = x * y;
                break;
            case '/':
                res = x / y;
                break;
            }
            nums.push(res);
        }
    }
    printf("%.2f\n", nums.top());

    return 0;
}