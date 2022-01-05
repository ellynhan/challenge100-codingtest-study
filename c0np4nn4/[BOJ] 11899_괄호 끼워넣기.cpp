#include <iostream>
#include <stack>

using namespace std;

char prob[51] = {'\x00', };
stack<char> st;
int ret = 0;


int main() {
	cin >> prob;
	
	for (int i = 0; prob[i] != '\x00'; i++) {
		if ( st.empty() && prob[i] == ')' ) {
			ret++;
			continue;
		}
		if ( !st.empty() && prob[i] == ')' ) {
			st.pop();
		}
		if ( prob[i] == '(' ) {
			st.push('(');
		}
	}
	
	while(!st.empty()) {
		st.pop();
		ret++;
	}
	
	cout << ret << endl;
	return 0;
}
