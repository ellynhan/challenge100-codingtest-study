#include <iostream>
#include <string>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	string s;
	while(1) {
		int flag=1;
		cin >> s;
		int len = s.length();
		if(s[0]=='0') return 0;
		for(int i=0; i<len/2; i++) {
			if(s[i]!=s[len-1-i]) {
				cout << "no\n";
				flag=0;
				break;
			}
		}
		if(flag) {
			cout << "yes\n";
		}
	}
}