#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n, m;
vector<int> arr;

void solve(int rectmp, int tmp[], int cur) {
	if(rectmp == m) {
		for(int i=0; i<m; i++) {
			cout << tmp[i] << " ";
		}
		cout << "\n";
		return;
	}

	for(int i=cur; i<n; i++) {
		tmp[rectmp] = arr[i];
		solve(rectmp+1, tmp, i+1);
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp[10] = {};
	cin >> n >> m;
	arr.resize(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	solve(0, tmp, 0);
}