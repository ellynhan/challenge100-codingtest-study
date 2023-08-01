#include <iostream>
#include <stack>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string parenthesis;
		cin >> parenthesis;
		
		stack<char> s;
		for (int j = 0; j < parenthesis.length(); j++) {
			if (parenthesis[j] == '(') {
				s.push('(');
			}
			else if (parenthesis[j] == ')') {
				if (s.empty())	{
					s.push(')');
					break;
				}
				else {
					s.pop();
				}
			}
		}
		if (s.empty())
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
			
	}
}
