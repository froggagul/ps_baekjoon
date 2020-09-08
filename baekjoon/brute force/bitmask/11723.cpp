#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    string cmd;

    cin >> n;
    int curr = 0;   // 0 ~ 19
    while (n--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> num;
            if ((curr & (1 << (num - 1))) == 0) {
                curr = curr | (1 << (num - 1));
            }
        }
        else if (cmd == "remove") {
            cin >> num;
            if ((curr & (1 << (num - 1))) > 0) {
                curr = curr & ~(1 << (num - 1));
            }
        }
        else if (cmd == "check") {
            cin >> num;
            if ((curr & (1 << (num - 1))) > 0) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (cmd == "toggle") {
            cin >> num;
            curr = curr ^ (1 << (num - 1));
        }
        else if (cmd == "all") {
            curr = (1 << 20) - 1;
        }
        else if (cmd == "empty") {
            curr = 0;
        }
    }
    return 0;
}