#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

bool check[1000001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n,m;
	cin >> n >> m;
	check[1]=1;
	for(ll i=2; i<=m; i++) {
		if(!check[i]) {
			for(ll j=2; i*j<=m; j++) {
				check[i*j]=1;
			}
		}
	}

	ll sum=0;
	bool flag=1;
	int minval = -1;
	for(int i=n; i<=m; i++) {
		if(!check[i]) {
			sum+=i;
			if(flag) {
				minval = i;
				flag=0;
			}
		}
	}
	if(sum==0) cout << -1;
	else cout << sum << "\n" << minval;
}