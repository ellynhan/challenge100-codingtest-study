#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> g[1001];
bool v[1001] = {};

void dfs(int x) {
	v[x] = 1;
	for(auto y: g[x]) {
		if(!v[y]) {
			dfs(y);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b;
	
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int cnt = 0;
	for(int i=1; i<=n; i++) {
		if(!v[i]) {
			// cout << i << "\n";
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;
}