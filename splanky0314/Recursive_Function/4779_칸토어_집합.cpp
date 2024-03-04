#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll pow(int x) {
	if(x==0) return 1;
	ll tmp = pow(x/2);
	if(x%2==1) return 3*tmp*tmp;
	else return tmp*tmp;
}

void solve(int x, bool check) {
	if(check==0) {
		for(int i=0; i<pow(x); i++) {
			cout << " ";
		}
	}
	else {
		if(x==0) {
			cout << "-";
		}
		else {
			solve(x-1, 1);
			solve(x-1, 0);
			solve(x-1, 1);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	while(cin >> n) {
		solve(n,1);
		cout << "\n";
	}
}