#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	string a, b;
	
	cin >> a >> b;
	a = " " + a;
	b = " " + b;

	int alen = a.length();
	int blen = b.length();
	int maxval=-1;

	for(int i=1; i<alen; i++) {
		for(int j=1; j<blen; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if(a[i]==b[j]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
			}
			if(dp[i][j]>maxval) maxval = dp[i][j];
		}
	}

	cout << maxval;
}