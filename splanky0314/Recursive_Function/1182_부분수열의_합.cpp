#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int n, s;
int arr[21];
int cnt = 0;

void solve(int rec, int rectmp, ll sum, int num) {
	if(rec==rectmp) {
		if(sum==s) {
			cnt++;
		}
		return;
	}

	for(int i=num; i<n; i++) {
		solve(rec, rectmp+1, sum+arr[i], i+1);
	}

	
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> s;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	for(int i=1; i<=n; i++) {
		solve(i, 0, 0, 0);
	}
	cout << cnt;
}