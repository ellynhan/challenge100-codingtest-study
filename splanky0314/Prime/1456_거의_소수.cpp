#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

bool check[10000001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll a, b, cnt = 0;
	cin >> a >> b;

	for(ll i=2; i<=sqrt(b); i++) {
		if(!check[i]) {
			ll tar = i;
			while((double)i<=double(b)/double(tar)) {
				if((double)i>=(double)a/double(tar)) {
					cnt++;
					//cout << tar << endl;
				}
				// if(tar*i <= 0)  {
				// 	break; // overflow 처리
				// }
				tar*=i;
			}
			for(ll j=2; i*j<=sqrt(b); j++) {
				check[i*j] = 1;
			}
			//cout << "finr!!" << endl;
		}
	}

	cout << cnt;
}