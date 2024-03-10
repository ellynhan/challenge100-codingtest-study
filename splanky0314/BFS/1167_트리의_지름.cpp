#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
using ll = long long;

bool v[100001];
vector<pair<int,int>> g[100001];
int distance_table[100001];

void bfs(int x) {
	queue<int> q;
	v[x] = 1;
	q.push(x);
	distance_table[x] = 0;
	while(!q.empty()) {
		x = q.front();
		q.pop();
		for(auto y: g[x]) {
			if(!v[y.first]) {
				v[y.first] = 1;
				q.push(y.first);
				distance_table[y.first] = distance_table[x] + y.second;
			}
		}
	}
}

int find_max_node(int n) {
	int maxidx = 1;
	for(int i=2; i<=n; i++) {
		//cout << i << ": " << distance_table[i] << endl; // 
		if(distance_table[maxidx] < distance_table[i]) {
			maxidx = i;
		}
	}
	return maxidx;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int vcin, a, b, wtmp;
	cin >> vcin;
	for(int i=0; i<vcin; i++) {
		cin >> a;
		while(1) {
			cin >> b;
			if(b==-1) break;
			cin >> wtmp;
			g[a].push_back({b, wtmp});
		}
	}

	bfs(1);
	int target = find_max_node(vcin);
	fill_n(distance_table, vcin+1, 0);
	fill_n(v, vcin+1, false);
	bfs(target);
	cout << distance_table[find_max_node(vcin)];	
}