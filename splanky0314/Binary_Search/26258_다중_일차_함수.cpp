#include <iostream>
#include <vector>
using namespace std;

int n,q;
vector<pair<long long,long long>> p;
void search(double tar) {
	int l=1, r=n-1, mid;
	while(l<r) {
		mid = (l+r)/2;
		if(p[mid].first<=tar) l=mid+1;
		else r=mid;  
	}

	if(p[l].second>p[l-1].second) cout << 1 << "\n";
	else if(p[l].second<p[l-1].second) cout << -1 << "\n";
	else cout << 0 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	double k;
	cin >> n;
	p.resize(n);
	for(int i=0; i<n; i++) {
		cin >> p[i].first >> p[i].second;
	}

	cin >> q;
	for(int i=0; i<q; i++) {
		cin >> k;
		search(k);
	}
}