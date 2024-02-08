//
//  PALINDROMIZE.cpp
//  main
//
//  Created by wi_seong on 1/22/24.
//

/*
 [Input]
 3
 there
 amanaplanacanal
 xyz
 [Output]
 7
 21
 5
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: 하
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/PALINDROMIZE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t;

vector<int> failure(string& s) {
    int n = int(s.size());
    vector<int> f(n);
    int j = 0;

    for(int i = 1; i < n; i++) {
        while(j > 0 && s[i] != s[j]) j = f[j - 1];
        if(s[i] == s[j]) f[i] = ++j;
    }

    return f;
}

int maxOverlap(string& a, string& b) {
    vector<int> f = failure(b);
    int n = int(a.size());
    int m = int(b.size());
    int begin = 0;
    int matched = 0;

    while(begin < n) {
        if(matched < m && a[begin + matched] == b[matched]) {
            ++matched;
            if(begin + matched == n) return matched;
        } else {
            if(matched == 0) begin++;
            else {
                begin += matched - f[matched - 1];
                matched = f[matched - 1];
            }
        }
    }

    return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        string s; cin >> s;
        string r = s;
        reverse(r.begin(), r.end());
        cout << s.length() * 2 - maxOverlap(s, r) << '\n';
    }

	return 0;
}
