//
//  JAEHASAFE.cpp
//  main
//
//  Created by wi_seong on 1/22/24.
//

/*
 [Input]
 2
 3
 abbab
 babab
 ababb
 bbaba
 2
 RMDCMRCD
 MRCDRMDC
 DCMRCDRM
 [Output]
 6
 10
 */
// 시간복잡도: O(L)
// 최악시간: 10,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/JAEHASAFE

#include <iostream>
#include <vector>

using namespace std;
int t, k;

vector<int> failure(const string& s) {
    int n = int(s.size());
    vector<int> f(n);
    int j = 0;

    for(int i = 1; i < n; i++) {
        while(j > 0 && s[i] != s[j]) j = f[j - 1];
        if(s[i] == s[j]) f[i] = ++j;
    }

    return f;
}

vector<int> kmpSearch(const string& s, const string& p) {
    int n = int(s.size());
    int m = int(p.size());
    vector<int> f = failure(p);

    int matched = 0;
    vector<int> ret;

    for(int i = 0; i < n; i++) {
        while(matched > 0 && s[i] != p[matched]) {
            matched = f[matched - 1];
        }

        if(s[i] == p[matched]) {
            matched++;

            if(matched == m) {
                ret.push_back(i - m + 1);
                matched = f[matched - 1];
            }
        }
    }

    return ret;
}

int shifts(const string& original, const string& target) {
    return kmpSearch(original + original, target)[0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> k;
        string s, target;
        cin >> s;
        int ans = 0;
        bool flag = false;

        while(k--) {
            cin >> target;
            if(flag) ans += shifts(s, target);
            else ans += shifts(target, s);

            s = target;
            flag = !flag;
        }
        cout << ans << '\n';
    }

	return 0;
}
