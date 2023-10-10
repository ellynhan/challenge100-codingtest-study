#include <iostream>

using namespace std;
using ll = long long;

int n;
ll cnt=0;
bool v1[15];
bool v2[30];
bool v3[30];

// x: 행, j: 열
void dfs(int x) {
	if(x==n) {
		cnt++;
		return;
	}

	for(int j=0; j<n; j++) {
		if(!v1[j] && !v2[x+j] && !v3[n-1+x-j]) {
			v1[j]=1;
			v2[x+j]=1;
			v3[n-1+x-j]=1;
			dfs(x+1);
			v1[j]=0;
			v2[x+j]=0;
			v3[n-1+x-j]=0;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dfs(0);
	cout << cnt;
}