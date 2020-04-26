#include <iostream>
#include <string>
using namespace std;

int main()
{
    int c[26] = { 0 };
    string str;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
        c[str[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        cout << c[i] << " ";


    return 0;
}