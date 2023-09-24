#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n;
	vector<string> s[51];
	cin >> n;
	for(int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		s[tmp.length()].push_back(tmp);
	}

	for(int i=1; i<=50; i++) {
		int len = s[i].size();
		if(len==0) continue;
		else if(len>=2) {
			sort(s[i].begin(), s[i].end());
			for(int j=0; j<len; j++) {
				if(j>0 && s[i][j-1]==s[i][j]) {
					continue;
				}
				else cout << s[i][j] << "\n";
			}
		}
		else cout << s[i][0] << "\n";
	}
}