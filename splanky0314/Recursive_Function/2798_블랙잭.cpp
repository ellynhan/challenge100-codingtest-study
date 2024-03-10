#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n,m;
vector<int> arr(101);
int maxval = -1;

void solve(int index, int cnt, ll sum) {
	if(sum>m) return;
	if(cnt==3) {
		if(maxval==-1 || maxval<sum) {
			maxval = sum;
		}
		return;
	}
	for(int i=index; i<n; i++) {
		solve(i+1, cnt+1, sum+arr[i]);
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	solve(0, 0, 0);
	cout << maxval;
	
}