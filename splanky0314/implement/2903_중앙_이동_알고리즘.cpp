#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, ans=2;
	cin >> n;

	for(int i=0; i<n; i++) {
		ans += ans-1;
	}
	cout << ans*ans;
}