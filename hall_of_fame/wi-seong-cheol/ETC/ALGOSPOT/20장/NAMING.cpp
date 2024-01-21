//
//  NAMING.cpp
//  main
//
//  Created by wi_seong on 1/20/24.
//

/*
 [Input]
 ababcabababa
 bcabab
 [Output]
 2 4 9 18
 */
// 시간복잡도: O(n)
// 최악시간: 400,000
// 난이도: 하
// Timer: 20m
// Url: https://algospot.com/judge/problem/read/NAMING

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
string father, mother, s;

vector<int> failure() {
    vector<int> f(n);
    int j = 0;

    for(int i = 1; i < n; i++) {
        while(j > 0 && s[i] != s[j]) j = f[j - 1];
        if(s[i] == s[j]) f[i] = ++j;
    }

    return f;
}

vector<int> solve() {
    vector<int> ret;
    vector<int> f = failure();
    int k = n;

    while(k > 0) {
        ret.push_back(k);
        k = f[k - 1];
    }
    sort(ret.begin(), ret.end());

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> father >> mother;
    s = father + mother;
    n = int(s.size());
    vector<int> ans = solve();
    for(int x : ans) cout << x << " ";

	return 0;
}
