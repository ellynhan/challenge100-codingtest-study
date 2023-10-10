#include <iostream>

using namespace std;
using ll = long long;

int n;
int memo[1001][1001];

int f(int x, int tar) {
	if(x==n) return 10-tar;
	if(memo[x][tar]) return memo[x][tar];

	ll sum=0;
	for(int i=tar; i<=9; i++) {
		sum = (sum+f(x+1, i))%10007;
	}
	return memo[x][tar] = sum;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << f(1,0);
}