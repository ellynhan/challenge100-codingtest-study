#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp;
	vector<int> v;
	v.push_back(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	for(int i=2; i<=n; i++) {
		for(int j=i-1; j>=0; j--) {
			if(v[j] < v[i]) {
				for(int k=i; k>j+1; k--) {
					swap(v[k-1], v[k]);
				}
				break;
			}
		}
	}

	// for(int i=0; i<v.size(); i++) {
	// 	cout << v[i] << " ";
	// }

	ll sum = 0;
	for(int i=1; i<v.size(); i++) {
		sum += (n-i+1)*v[i];
	}
	cout << sum;
}