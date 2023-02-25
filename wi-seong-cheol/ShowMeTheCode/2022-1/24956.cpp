
//  24956.cpp
//  main
//
//  Created by wi_seong on 2023/01/16.
//

/*
 [Input]
 8
 WAHEWHEE
 [Output]
 6
 */
// 시간복잡도: O(n)
// 최악시간: 200,000
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/24956

#include <iostream>
#include <vector>

using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n;
string s;
ll ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >>  s;
    vector<ll> two(n + 1);
    two[0] = 1;
    for(int i = 1; i <= n; i++) {
        two[i] = two[i - 1] * 2;
        two[i] %= mod;
    }
    vector<int> cnt_w(n);
    if(s[0] == 'W') {
        cnt_w[0] = 1;
    }
    for(int i = 1; i < n; i++) {
        if (s[i] == 'W') {
            cnt_w[i] = cnt_w[i - 1] + 1;
        } else {
            cnt_w[i] = cnt_w[i - 1];
        }
    }
    vector<int> cnt_e(n);
    if(s[n - 1] == 'E') {
        cnt_e[n - 1] = 1;
    }
    for(int i = n - 2; i >= 0; i--) {
        if(s[i] == 'E') {
            cnt_e[i] = cnt_e[i + 1] + 1;
        } else {
            cnt_e[i] = cnt_e[i + 1];
        }
    }
    for(int j = 1; j < n - 1; j++) {
        if(s[j] != 'H') continue;
        int w = cnt_w[j - 1];
        int e = cnt_e[j + 1];
        ll cur = (two[e] - e - 1 + mod) % mod;
        ans += w * cur;
        ans %= mod;
    }
    cout << ans;
    
    return 0;
}
