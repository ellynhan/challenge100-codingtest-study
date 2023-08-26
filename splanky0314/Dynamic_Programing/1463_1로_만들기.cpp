#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> memo(1000001);

int solve(int x) {
	if(memo[x]) return memo[x];

	int tmp[3] = {-1,-1,-1};
	if(x%3==0) {
		tmp[0] = solve(x/3);
	}
	if(x%2==0) {
		tmp[1] = solve(x/2);
	}
	tmp[2] = solve(x-1);
	int minval = tmp[2];

	
	for(int i=0; i<2; i++) {
		if(tmp[i]!=-1 && minval>tmp[i]) {
			minval = tmp[i];
		}
	}
	return memo[x] = minval+1;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	memo[0] = 0;
	memo[1] = 1;

	int n;
	cin >> n;
	cout << solve(n)-1;
}