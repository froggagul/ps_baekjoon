#include <iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(nullptr); // cin이 빠르게 실행되기 위해 필요한 코드
	int n;
	cin >> n;
	cin.ignore(); // cin은 \n을 변수에 담지 않고 입력버퍼에 남겨놓는다. getline은 \n을 변수에 담는다. 
    // 따라서, 맨 앞의 문자하나를 지우는  cin.ignore()가 필요하다.
	while (n--) {
		string str;
		getline(cin, str);
		str += '\n';
		stack<char> stack;
		for (int i = 0; i < str.size(); i++) { // c++ 11이상에서는 char ch: str도 가능하다.
			char ch = str[i];
			if (ch == ' ' || ch == '\n') {
				while (!stack.empty()) {
					cout << stack.top();
					stack.pop();
				}
				cout << ch;
			}
			else {
				stack.push(ch);
			}
		}
	}
	return 0;
}