#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p[100001];
vector<int> g[100001];

void dfs(int x) {
	for(auto y:g[x])
		if(!p[y]) {
			p[y] = x;
			dfs(y);
		}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,a, b;
	cin >> n;
	for(int i=0; i<n-1; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	for(int i=2; i<=n; i++) {
		cout << p[i] << "\n";
	}
}