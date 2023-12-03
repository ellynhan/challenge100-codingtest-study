#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int arr[128][128];
int cnt0=0;
int cnt1=0;

void solve(int a1, int a2, int b1, int b2) {
	int cnt[2] = {};
	bool flag = false;
	if(a1==a2 && b1==b2) {
		if(arr[a1][b1]==0) cnt0++;
		else cnt1++;
		return;
	}
	for(int i=a1; i<a2; i++) {
		for(int j=b1; j<b2; j++) {
			cnt[arr[i][j]]++;
			if(cnt[0]&&cnt[1]) {
				flag = true;
				break;
			}
		}
		if(flag) break;
	} 

	if(flag) {
		int amid = (a1+a2)/2-a1;
		int bmid = (b1+b2)/2-b1;
		solve(a1, a1+amid, b1, b1+bmid);
		solve(a1, a1+amid, b1+bmid, b2);
		solve(a1+amid, a2, b1, b1+bmid);
		solve(a1+amid, a2, b1+bmid, b2);
	}
	else {
		if(cnt[0]) cnt0++;
		else if(cnt[1]) cnt1++;
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0,n,0,n);

	cout << cnt0 << "\n" << cnt1;
}