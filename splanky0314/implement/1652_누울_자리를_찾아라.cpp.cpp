#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> s;
	string tmp;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		s.push_back(tmp);
	}

	int cntu = 0, cntr = 0;
	for(int i=0; i<n; i++) {
		int tmpu = 0, tmpr = 0;
		bool flagu = true, flagr = true;
		for(int j=0; j<n; j++) {
			if(flagr && s[i][j]=='.') tmpr++;
			else if(s[i][j]=='X') {
				tmpr = 0;
				flagr = true;
			}
			if(flagu && s[j][i]=='.') tmpu++;
			else if(s[j][i]=='X') {
				tmpu = 0;
				flagu = true;
			}
			if(flagr && tmpr>1) {
				cntr++;
				flagr = false;
				tmpr = 0;
			}
			if(flagu && tmpu>1) {
				cntu++;
				flagu = false;
				tmpu = 0;
			}
		}
	}

	cout << cntr << " " << cntu;
}