#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int n, m;
vector<int> arr;
bool check[10];

void solve(int rectmp, int tmp[]) {
	if(rectmp == m) {
		for(int i=0; i<m; i++) {
			cout << tmp[i] << " ";
		}
		cout << "\n";
		return;
	}

	for(int i=0; i<n; i++) {
		bool flag = 1;
		if(check[i]==0) {
			tmp[rectmp] = arr[i];
			check[i] = 1;
			solve(rectmp+1, tmp);
			check[i] = 0;
		}
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
	solve(0, tmp);
}