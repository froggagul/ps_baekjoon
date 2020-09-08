#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<stack>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int alphabet[26] = { 0, };
    for (int i = 0; i < 26; i++) {
        alphabet[i] = -1;
    }
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if (alphabet[str[i] - 'a'] == -1) {
            alphabet[str[i] - 'a'] = i;
        }
    }
    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }
    return 0;
}