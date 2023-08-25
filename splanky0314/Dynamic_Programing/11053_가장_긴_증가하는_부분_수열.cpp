#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n, max;
	cin >> n;
	vector<int> v(n), dp(n,0);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	
	dp[0]=1;
	for(int i=1; i<n; i++) {
		max = 0;
		for(int j=0; j<i; j++) {
			if(v[j]<v[i] && max < dp[j]) {
				max = dp[j];
			}
		}
		dp[i] = max+1;
	}

	max=0;
	for(int i=0; i<n; i++) {
		if(max < dp[i]) max = dp[i];
	}
	cout << max;
}