#include <iostream>
#include <vector>
using namespace std;

int memo[1000001]={};
long long f(int n) {
	long long cnt=0;
	if(memo[n]) {
		return memo[n];
	}
	return memo[n] = (f(n-3)+f(n-2)+f(n-1))%1000000009;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;

	int t, n;
	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> n;
		cout << f(n) << "\n";
	}
}