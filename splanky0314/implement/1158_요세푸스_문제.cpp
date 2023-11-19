#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, cnt, roop = 0, tmp = 0;
	vector<int> v;
	cin >> n >> k;
	cnt = k-1;
	for(int i=1; i<=n; i++) {
		v.push_back(i);
	}

	cout << "<" << v[cnt];
	roop++;
	v[cnt] = -1;
	cnt = (cnt+1)%n;
	while(roop!=n) {
		if(v[cnt]==-1) {
			cnt = (cnt+1)%n;
			continue;
		}
		tmp++;
		if(tmp==k) {
			cout << ", " << v[cnt];
			v[cnt] = -1;
			roop++;
			tmp = 0;
		}	
		cnt = (cnt+1)%n;
	}
	cout << ">";
}