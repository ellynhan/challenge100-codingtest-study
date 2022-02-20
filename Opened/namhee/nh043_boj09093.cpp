#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	// 1. INPUT T - num of testcase
	int T;
	cin >> T;
	cin.ignore();
	
	for (int i = 0; i < T; i++) {
		// 2. INPUT STRING
		string str;
		getline(cin, str);
		str += ' ';
		
		// 3. WORD REVERSAL & OUTPUT WORD
		stack<char> s;
		for (char c : str) {
			if (c == ' ') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
			else
				s.push(c);
		}
		
	}
}

