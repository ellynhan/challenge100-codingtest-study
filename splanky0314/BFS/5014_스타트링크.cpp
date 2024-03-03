#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;

bool v[1000001];

int bfs(ll s, ll tar, ll f, ll u, ll d) {
	queue<pair<ll,ll>> q;
	q.push({s,0});
	v[s]=1;
	while(!q.empty()) {
		pair<ll,ll> tmp = q.front();
		ll state = get<0>(tmp);
		q.pop();
		if(state==tar) {
			return get<1>(tmp);
		}
		if(state-d>=1 && !v[state-d]) {
			q.push({state-d, get<1>(tmp)+1});
			v[state-d]=1;
		}
		if(state+u<=f && !v[state+u]) {
			q.push({state+u, get<1>(tmp)+1});
			v[state+u]=1;
		}
	}
	return -1;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll f,s,g,u,d;
	cin >> f >> s >> g >> u >> d;
	ll ans = bfs(s,g,f,u,d);
	if(ans==-1) cout << "use the stairs";
	else cout << ans;
}