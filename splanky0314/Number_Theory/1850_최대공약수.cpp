#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll a, b;
	cin >> a >> b;

	ll cnt = gcd(a,b);
	for(ll i=0; i<cnt; i++) {
		cout << "1";
	}
}