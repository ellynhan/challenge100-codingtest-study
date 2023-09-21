#include <iostream>

using namespace std;
using ll = long long;

bool check[1000];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n, k;
	cin >> n >> k;
	int cnt=0;
	for(ll i=2; i<=n; i++) {
		if(!check[i]) {
			check[i]=1;
			cnt++;
			if(cnt==k) {
				cout << i;
				return 0;
			}
			for(ll j=2; i*j<=n; j++) {
				if(!check[i*j]) {
					check[i*j]=1;
					cnt++;
					if(cnt==k) {
						cout << i*j;
						return 0;
					}
				}
			}
		}
	}
}