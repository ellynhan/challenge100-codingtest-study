#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

ll com(int a, int b) {
	ll sum=1;
	int tmp = a;
	int div = 1;
	for(int i=0; i<(a-b<b?a-b:b); i++) {
		sum *= tmp--;
		sum /= div++;
	}
	return sum;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m;
	cin >> t;
	for(int T=0; T<t; T++) {
		cin >> n >> m;
		if(n<m) swap(n, m);
		cout << com(n,m) << "\n";
	}
}