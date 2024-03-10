#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
bool check[1000001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	
	cin >> n;
	ll ans = n;
	// 에라토스테네스의 체
	for(ll i=2; i<=sqrt(n); i++) {
		// 오일러 퍼
		if(!check[i] && n%i==0) {
			ans = ans - ans/i;
		}
		while(n%i==0) {
			n/=i;
		}
		
		if(!check[i]) {
			for(ll j=2; i*j<=sqrt(n); j++) {
				check[i*j] = 1;
			}
		}
	}
	if(n>1) {
		ans = ans - ans/n;
	}

	cout << ans;
}