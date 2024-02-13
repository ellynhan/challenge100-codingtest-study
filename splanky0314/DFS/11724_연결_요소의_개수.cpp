#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

bool v[1001];
vector<int> g[1001];

void bfs(int x) {
	queue<int> q;
	v[x] = 1;
	q.push(x);

	while(!q.empty()) {
		x = q.front();
		q.pop();
		v[x] = 1;
		for(auto y:g[x]) {
			if(!v[y]) {
				v[y] = 1;
				q.push(y);
			}
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
			bfs(i);
			cnt++;
		}
	}

	cout << cnt;
}