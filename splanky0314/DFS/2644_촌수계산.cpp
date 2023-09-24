#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<int> g[101];
bool v[101];
bool flag=0;

void dfs(int x, int tar, int cnt) {
	if(x==tar) {
		cout << cnt;
		flag=1;
		return;
	}
	v[x]=1;
	for(auto y:g[x]) {
		if(!v[y]) {
			dfs(y, tar, cnt+1);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n, m, a,b;
	cin >> n >> a >> b >> m;
	for(int i=0; i<m; i++) {
		int p,q;
		cin >> p >> q;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	dfs(a,b,0);
	if(!flag) cout << -1;
}