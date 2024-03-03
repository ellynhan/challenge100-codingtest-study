#include <iostream>
using namespace std;

long long n;

long long search(long long tar) {
	long long l=0, r=n;
	double mid;
	while(l<r) {
		mid = (l+r)/2;
		if(mid*mid>=tar) r = mid;
		else l = mid+1;
	}
	return l;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> n;
	cout << search(n);
}