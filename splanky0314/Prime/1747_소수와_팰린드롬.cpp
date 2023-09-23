#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool check[1003002];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n;
	cin >> n;

	check[1]=1;
	for(ll i=2; i<=1003001; i++) {
		if(!check[i]) {
			for(ll j=2; i*j<=1003001; j++) {
				check[i*j]=1;
			}
		}
	}

	for(int i=n; i<=1003001; i++) {
		if(!check[i]) {
			bool flag=1;
			string tmp = to_string(i);
			int fir=0, sec=tmp.length()-1;
			while(fir<sec) {
				if(tmp[fir]!=tmp[sec]) {
					flag=0;
					break;
				}
				fir++;sec--;
			}
			if(flag) {
				cout << i;
				return 0;
			}
		}
	}
}