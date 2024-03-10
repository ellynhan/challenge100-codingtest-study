#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a,b;
	vector<pair<int,int>> v;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a >> b;
		v.push_back({b, a});
	}
	sort(v.begin(), v.end());

	int cnt = 0;
	int idx = 0;
	for(int i=0; i<n; i++) {
		if(idx <= v[i].second) {
			idx = v[i].first;
			cnt++;
		}
	}
	cout << cnt;
}