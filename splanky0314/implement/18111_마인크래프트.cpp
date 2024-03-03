#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int arr[257];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, b, tmp;
	
	cin >> n >> m >> b;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> tmp;
			arr[tmp]++;
		}
	}

	ll minval = -1;
	ll minh = -1;
	for(int i=0; i<=256; i++) {
		ll sum=0;
		ll block=b;
		for(int j=0; j<=256; j++) {
			if(i<=j) {
				sum += 2*arr[j]*(j-i);
				block += arr[j]*(j-i);
			}
			else {
				sum += 1*arr[j]*(i-j);
				block -= 1*arr[j]*(i-j);
			}
		}

		if(block<0) break;

		if(minval==-1 || minval > sum) {
			minval = sum;
			minh = i;
		}
		else if(minval==sum && minh<i){
			minh = i;
		}
	}
	
	cout << minval << " " << minh;
}