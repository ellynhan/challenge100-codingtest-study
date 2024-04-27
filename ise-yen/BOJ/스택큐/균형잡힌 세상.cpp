#include<iostream>
#include<string>
#include<stack>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		string str;
		getline(cin, str, '\n');

		if (str == ".") {
			break;
		}

		bool isYes = true;
		stack<char> s;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				s.push('(');
			}
			else if(str[i] == ')'){
				if (s.empty()) {
					isYes = false;
					break;
				}
				else {
					if (s.top() == '(') s.pop();
					else {
						isYes = false;
						break;
					}
				}
			}
			else if (str[i] == '[') {
				s.push('[');
			}
			else if (str[i] == ']') {
				if (s.empty()) {
					isYes = false;
					break;
				}
				else {
					if (s.top() == '[') s.pop();
					else {
						isYes = false;
						break;
					}
				}
			}

			if (!isYes) break;
		}

		if (s.empty() && isYes) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}
