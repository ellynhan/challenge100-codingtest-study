#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n,m;
vector<int> check(1000001);
vector<int> v;

bool decision(long long t) {
	long long sum=0;
	for(int i=0; i<n; i++) {
		sum += t/v[i];
	}
	if(sum >= m) return 1;
	else return 0;
}

long long search() {
	long long l=1, r=1000000000000, mid;
	while(l<r) {
		mid = (l+r)/2;
		if(decision(mid)) r = mid;
		else l = mid+1;  
	}
	return l;
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

	cout << search();
}