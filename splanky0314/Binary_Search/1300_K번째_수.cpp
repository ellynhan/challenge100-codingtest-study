#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, k;
	cin >> n >> k;

	ll l = 1, r = k, mid;
	ll ans;
	while(l<=r) {
		ll sum = 0;
		mid = (l+r)/2;
		//cout << mid << " ";
		for(int i=1; i<=n; i++) {
			if(mid/i>n) {
				sum += n;
			}
			else sum += mid/i;
		}
		//cout << sum << " ";

		if(sum>=k) {
			r = mid-1;
			ans = mid;
		}
		else l = mid+1;
		//cout << endl;
	}
	cout << ans;
}