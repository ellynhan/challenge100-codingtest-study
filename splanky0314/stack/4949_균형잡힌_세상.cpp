#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(1) {
		stack<char> st;
		string input;
		int flag = 1;
		char target;
		getline(cin, input, '\n');
		if(input[0] == '.' && input.length()==1) {
			break;
		}

		for(int i=0; i<input.length(); i++) {
			if(input[i]=='(' || input[i]=='[') st.push(input[i]);
			if(input[i]==')' || input[i]==']') {
				if(input[i]==')') target = '(';
				else if(input[i]==']') target = '[';
				
				if(!st.empty() && st.top() == target) {
					st.pop();
				}
				else {
					cout << "no\n";
					flag = 0;
					break;
				}
			}
		}
		if(flag && st.empty()) cout << "yes\n";
		else if(flag) cout << "no\n";
	}
}