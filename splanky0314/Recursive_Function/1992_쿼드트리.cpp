#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<string> s;

void solve(int a1, int a2, int b1, int b2) {
	int cnt[2] = {};
	bool flag = false;
	for(int i=a1; i<a2; i++) {
		for(int j=b1; j<b2; j++) {
			cnt[s[i][j]-48]++;

			if(cnt[0]&&cnt[1]) {
				flag = true;
				break;
			}
		}
		if(flag) break;
	}
	//cout << "flag" << flag << endl;
	//cout << cnt[0] << ":" << cnt[1] << endl;
	if(flag) {
		int amid = (a1+a2)/2-a1;
		int bmid = (b1+b2)/2-b1;
		cout << "(";
		solve(a1, a1+amid, b1, b1+bmid);
		solve(a1, a1+amid, b1+bmid, b2);
		solve(a1+amid, a2, b1, b1+bmid);
		solve(a1+amid, a2, b1+bmid, b2);
		cout << ")";
	}
	else {
		if(cnt[0]) cout << 0;
		else cout << 1;
	}
	
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string tmp;
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		s.push_back(tmp);
	}
	solve(0,n,0,n);
}