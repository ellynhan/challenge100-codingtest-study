#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll n, k, tmp;
vector<ll> v;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	// Quick Sort!
	sort(v.begin(), v.end());

	cout << v[k-1];
}