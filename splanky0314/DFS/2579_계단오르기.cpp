#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int v[10001][3];
vector<int> arr;
int n;
int maxval;
void dfs(int x, int conti, ll sum) {
	if(x>n) return;
	if(conti==2) {
		return;
	}
	sum += arr[x];
	if(x==n) {
		if(maxval<sum) maxval = sum;
	}
	if(x>0 && v[x][conti]>sum) {
		return;
	}
	else if(x>0) {
		v[x][conti] = sum;
	}
	
	dfs(x+1, conti+1, sum);
	dfs(x+2, 0, sum);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	arr.push_back(0);
	for(int i=1; i<=n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	dfs(0,-1,0);
	cout << maxval;
}