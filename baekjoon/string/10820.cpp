#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<stack>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str)) {
        int lowCase = 0;
        int upperCase = 0;
        int number = 0;
        int space = 0;
        for (char ch : str) {
            if (ch >= 'A' && ch <= 'Z') {
                upperCase += 1;
            }
            else if (ch >= 'a' && ch <= 'z') {
                lowCase += 1;
            }
            else if (ch >= '0' && ch <= '9') {
                number += 1;
            }
            else if (ch == ' ') {
                space += 1;
            }
        }
        cout << lowCase << " " << upperCase << " " << number << " " << space << " " << '\n';
    }
    return 0;
}