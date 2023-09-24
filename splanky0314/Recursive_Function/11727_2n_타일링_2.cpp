#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

ll memo[1001];

ll f(int x) {
	if(x==0) return 1;
	if(memo[x]) return memo[x];
	ll cnt=0;
	if(x-2>=0) {
		cnt = (cnt+f(x-2)*2)%10007;
	}
	if(x-1>=0) {
		cnt = (cnt+f(x-1))%10007;
	}
	return memo[x] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n;
	cin >> n;
	cout << f(n);
}