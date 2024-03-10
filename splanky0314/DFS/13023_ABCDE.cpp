#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool flag = false;
bool v[2000];
vector<int> g[2000];

void dfs(int x, int cnt) {
	if(flag) return;

	if(cnt>=5) {
		cout << 1;
		flag = true;
		return;
	}
	v[x] = 1;
	for(auto y:g[x]) {
		if(!v[y]) {
			dfs(y, cnt+1);
		}
	}
	v[x] = 0;
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

	for(int i=0; i<n; i++) {
		dfs(i, 1);
		if(flag) break;
	}

	if(!flag) cout << 0;
}