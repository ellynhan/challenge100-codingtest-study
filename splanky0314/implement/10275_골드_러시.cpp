#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long pow(int a, int x) {
	if(x==0) return 1;
	long long tmp = pow(a, x/2);
	if(x%2==0) return tmp*tmp;
	else return tmp*tmp*a;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	long long t, n, a, b;
	cin >> t;
	for(int i=0; i<t; i++) {
		long long sum=0, cnt=0;;
		cin >> n >> a >> b;
		n = pow(2,n);
		long long min = a<b ? a:b;
		for(;;n/=2) {
			if(min-n>=0) {
				min-=n;
			}
			if(min==0) break;
			cnt++;
		}
		cout << cnt << "\n";
	}
}