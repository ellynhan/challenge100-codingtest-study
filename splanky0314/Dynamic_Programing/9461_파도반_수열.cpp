#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,n;
	cin >> t;
	for(int i=0; i<t; i++) {
		ll dp[3]={0,0,0};
		cin >> n;
		dp[0]=1;
		dp[1]=1;
		dp[2]=1;
		for(int j=0; j<n-3; j++) {
			dp[j%3]+=dp[(j+1)%3];
		}
		cout << dp[(n+2)%3] << "\n";
	}
	
}