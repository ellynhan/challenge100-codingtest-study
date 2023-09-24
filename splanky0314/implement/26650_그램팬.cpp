#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	string s;
	char tar = 0;
	long long cnt = 0;
	long long Acnt = 0;
	long long Zcnt = 0;
	cin >> s;
	
	for(int i=0; i<s.length(); i++) {
		if(s[i]==tar) {
			if(tar=='A') Acnt++;
			if(tar=='Z') {
				Zcnt++;
				if((i==s.length()-1)) {
					cnt += Acnt*Zcnt;
				}
			}
		}
		else if(s[i]==tar+1) {
			if(s[i]=='Z') {
				Zcnt++;
				if((i==s.length()-1)) {
					cnt += Acnt*Zcnt;
				}
			}
			tar++;
		}
		else if(tar=='Z') {
			cnt += Acnt*Zcnt;
			Acnt = 0;
			Zcnt = 0;
			tar = 0;
			if(s[i]=='A') {
				Acnt = 1;
				tar = 'A';	
			}
		}
		else if(s[i]=='A') {
			Acnt = 1;
			Zcnt = 0;
			tar = 'A';	
		}
		else {
			Acnt = 0;
			Zcnt = 0;
			tar = 0;
		}
	}

	cout << cnt;
}