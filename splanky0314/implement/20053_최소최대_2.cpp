#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

bool check[100000000];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int t, n, tmp;
	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> n;
		cin >> tmp;
		int maxval=tmp, minval=tmp;
		for(int j=1; j<n; j++) {
			cin >> tmp;
			if(maxval<tmp) maxval = tmp;
			if(minval>tmp) minval = tmp;
		}
		cout << minval << " " << maxval << "\n";
	}
}