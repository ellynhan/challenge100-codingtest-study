//
//  1893.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4
 ABC
 ABC
 ABCBBBABC
 ABC
 ABC
 ABCBCAABC
 D7a
 D7a
 D7aaD77aDD7a
 ABC
 ABC
 ABC
 [Output]
 no solution
 unique: 1
 ambiguous: 1 2
 unique: 0
 */
// 시간복잡도: O(k(n + m))
// 최악시간: 34,100,000
// 난이도: Platinum 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1893

#include <iostream>
#include <vector>

using namespace std;
string a, w, s;
vector<int> f;
int cnt[64];
int oa[257], ma[257];

vector<int> failure(string& s) {
    vector<int> f(s.size());
    int j = 0;
    for(int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) j = f[j - 1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

void solve() {
    f = failure(w);
    int as = (int)a.size();
    for(int k = 0; k < as; k++) {
        for(int i = 0; i < as; i++)
            ma[a[i]] = (oa[a[i]] + k) % as;
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            while(j > 0 && oa[s[i]] != ma[w[j]]) j = f[j - 1];
            if(oa[s[i]] == ma[w[j]]) j++;
            if(j == w.size()) {
                cnt[k]++;
                j = f[j - 1];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        vector<int> ans;
        fill(cnt, cnt + 64, 0);
        
        cin >> a >> w >> s;
        
        for(int i = 0; i < a.size(); i++)
            oa[a[i]] = i;
        
        solve();
        
        for(int i = 0; i < a.size(); i++)
            if(cnt[i] == 1) ans.push_back(i);
        
        if(ans.size() == 0)
            cout << "no solution\n";
        else if(ans.size() == 1)
            cout << "unique: " << ans[0] <<'\n';
        else {
            cout << "ambiguous: ";
            for(int x: ans) cout << x << ' ';
            cout <<'\n';
        }
    }
    
    return 0;
}
