#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

bool check[1000001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	for(ll i=3; i<=1000000; i+=2) {
		if(!check[i]) {
			for(ll j=3; i*j<=1000000; j+=2) {
				check[i*j]=1;
			}
		}
	}

	int n;
	while(1) {
		bool flag=1;
		cin >> n;
		if(n==0) return 0;

		for(int i=3; i*2<=n; i+=2) {
			if(!check[i] && !check[n-i]) {
				cout << n << " = " << i << " + " << n-i << "\n";
				flag=0;
				break;
			}
		}
		if(flag) cout << "Goldbach's conjecture is wrong.\n";
	}
}