#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
vector<int> g[10];
int dx[] = {1,3,7,9};

bool check_prime(int x) {
	for(int i=2; i<=x/2; i++) {
		if(x%i==0) return false;
	}
	return true;
}

void dfs(int x, int cnt) {
	if(cnt>=n) {
		cout << x << "\n";
		return;
	}

	int num;
	for(int k=0; k<4; k++) {
		num = x*10 + dx[k];
		if(check_prime(num)) {
			dfs(num, cnt+1);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);
}