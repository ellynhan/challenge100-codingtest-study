#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a(1001);
int n;

int solve() {
	vector<int> dp(n);
	dp[0] = a[0];
	int maxval=a[0];

	for(int i=1; i<n; i++) {
		if(dp[i-1]>0) {
			dp[i] = dp[i-1]+a[i];
		}
		else {
			dp[i] = a[i];
		}
		if(dp[i]>maxval) maxval = dp[i];
	}

	return maxval;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int t, tmp;
	cin >> t;
	for(int i=0; i<t; i++) {
		int cnt=0;
		cin >> n;
		for(int j=0; j<n; j++) {
			cin >> a[j];
			if(a[j]>0) cnt++;
		}

		if(cnt==0) {
			int maxval = a[0];
			for(int j=0; j<n; j++) {
				if(maxval < a[j]) maxval = a[j];
			}
			cout << maxval;
		}
		else if(cnt==1) {
			for(int j=0; j<n; j++) {
				if(a[j]>0) {
					cout << a[j];
					break;
				}
			}
		}
		else {
			cout << solve();
		}
		cout << "\n";
	}
}