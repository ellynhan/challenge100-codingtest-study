#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> arr;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, bud, sum=0;
	cin >> n;
	arr.resize(n,0);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	cin >> bud; 
	sort(arr.begin(), arr.end());
	if(sum<=bud) {
		cout << arr[n-1];
		return 0;
	}

	int l=0, r=bud;
	int mid, befmid=-1,befl=-1;
	while(l<=r) {
		mid = (l+r+1)/2;
		int cnt = 0;
		for(int i=0; i<n; i++) {
			if(mid<arr[i]) cnt+=mid;
			else cnt+=arr[i];
		}
		//cout << l << ":" << r <<" "<< mid << endl;
		if(cnt<=bud) {
			l = mid;
			if(mid==befmid && l==befl) {
				break;
			}
		}
		else {
			r = mid-1;
		}
		befmid = mid;
		befl = l;
	}
	cout << r;
}