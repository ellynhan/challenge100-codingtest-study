#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

bool check[1000010];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll min, max, cnt = 0, realmin;
	cin >> realmin >> max;

	if(sqrt(realmin)==1) {
		min = 4;
	}
	else min = realmin;
	for(ll i=2; i<=sqrt(max); i++) {
		ll tar = i*i;


		for(ll j=double(min)/double(tar) - 1; tar*j<=max; j++) {
			if(min<=tar*j) {
				if(check[tar*j-min]==1) {

				}
				else {
					check[tar*j-min] = 1;
					cnt++;
					//cout << tar*j << endl;
				}
			}
			
		}
		
		
		
	}
	//cout << "!" << cnt << endl;
	cout << max-realmin+1-cnt;
}