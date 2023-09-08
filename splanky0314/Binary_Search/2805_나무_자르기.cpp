#include <iostream>
#include <vector>
using namespace std;

long n,m;
vector<int> v;

bool solve(long long mid) {
	long long sum=0;
	for(int i=0; i<n; i++) {
		if(v[i]-mid<0) continue;
		else sum += v[i]-mid;
	}

	return sum>=m;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> n >> m;
	v.resize(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}

	long long l=0, r=1000000000;
	while(l<r) {
		double tmp = double(l+r)/2+0.5;
		long long mid = tmp;
		if(solve(mid)) l = mid;
		else r = mid-1;
	}
	cout << r;
}