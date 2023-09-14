#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool v1[1001];
bool v2[1001];
vector<int> g[1001];

void dfs(int x) {
	v1[x]=1;
	cout << x << " ";
	for(auto y:g[x]) {
		if(!v1[y]) {
			dfs(y);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	v2[x]=1;
	while(!q.empty()) {
		int x = q.front();
		cout << x << " ";
		q.pop();
		for(auto y:g[x]) {
			if(!v2[y]) {
				q.push(y);
				v2[y]=1;
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n, m, v;
	int a,b;
	cin >> n >> m >> v;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		g[b].push_back(a);
		g[a].push_back(b);
	}
	for(int i=1; i<=n; i++) {
		sort(g[i].begin(), g[i].end());
	}

	dfs(v);
	cout << "\n";
	bfs(v);
}