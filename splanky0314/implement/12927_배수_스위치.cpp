#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	string s;
	long cnt=0;
	cin >> s;
	s = " "+s;
	for(int i=1; i<s.length(); i++) {
		if(s[i]=='Y') {
			for(int j=2; i*j<s.length(); j++) {
				if(s[i*j]=='N') s[i*j]='Y';
				else s[i*j]='N';
			}
			cnt++;
		}
	}
	cout << cnt;
}