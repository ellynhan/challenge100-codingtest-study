#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m, val;
	
	cin >> t;
	for(int T=0; T<t; T++) {
		queue<int> q;
		vector<int> v;
		int cnt = 0;
		cin >> n >> m;
		for(int i=0; i<n; i++) {
			cin >> val;
			q.push(i);
			v.push_back(val);
		}

		while(!q.empty()) {
			bool flag = true;
			for(int i=0; i<n; i++) {
				if(v[i]>v[q.front()]) {
					q.push(q.front());
					q.pop();
					flag = false;
					break;
				}
			}
			if(flag) {
				cnt++;
				if(q.front()==m) {
					cout << cnt << "\n";
					break;
				}
				v[q.front()] = -1;
				q.pop();
			}
		}
	}

}