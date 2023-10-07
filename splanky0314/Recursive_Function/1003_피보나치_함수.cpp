#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int cnt[2];
vector<pair<int,int>> memo(41);

pair<int,int> fibo(int n, pair<int,int> p) {
	if(memo[n].first || memo[n].second) {
		return {p.first += memo[n].first, p.second += memo[n].second};
	}

    if (n == 0) {
		return {p.first+1, p.second};
    } 
	else if(n == 1) {
		return {p.first, p.second+1};
	}
	else {
		auto a = fibo(n-1,{0,0});
		auto b = fibo(n-2,{0,0});
        return memo[n] = {p.first+a.first+b.first, p.second+a.second+b.second};
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,n;
	cin >> t;
	for(int i=0; i<t; i++) {
		cnt[0] = 0;
		cnt[1] = 0;
		cin >> n;
		cout << fibo(n, {0,0}).first << " " << fibo(n, {0,0}).second << "\n";
	}
}