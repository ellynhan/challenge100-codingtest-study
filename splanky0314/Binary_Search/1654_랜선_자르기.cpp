#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int k, n;
vector<long long> v;

bool solve(long long mid) {
	long long sum=0;
	for(int i=0; i<k; i++) {
		sum +=  v[i]/mid;		
	}
	return sum>=n;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> n;
	v.resize(k);
	for(int i=0; i<k; i++) {
		cin >> v[i];
	}

	long long l=1, r=2147483647;
	while(l<r) {
		double tmp = double(l+r)/2+0.5;
		long long mid = tmp;
		if(solve(mid)) l = mid;
		else r = mid-1;
	}
	cout << r;
}