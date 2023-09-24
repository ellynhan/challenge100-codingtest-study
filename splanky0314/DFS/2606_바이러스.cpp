#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool v[101];
vector<int> g[101];
int cnt=0;

void dfs(int x) {
	cnt++;
	v[x]=1;
	for(auto y:g[x]) {
		if(!v[y]) {
			dfs(y);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n,t;
	cin >> n >> t;
	for(int i=0; i<t; i++) {
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);
	cout << cnt-1;
}