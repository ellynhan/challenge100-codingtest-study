//
//  1086.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/23.
//

/*
 [Input]
 3
 3
 2
 1
 2
 [Output]
 1/3
 */
// 시간복잡도: O(2^N * N * K)
// 최악시간: 49,152,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1086

#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>

using namespace std;
#define ll long long
int n, k;
string s[16];
ll v[16];       // v[i] = s[i]를 수로 변환
ll pow10[51];    // pw10[i] = 10 ^ i % k
ll d[1 << 16][101];
int sz[51];     //s[i]의 길이

ll solve(int bit, int num) {
    if(bit == (1 << n) - 1)
        return !num;
    if(d[bit][num] != -1)
        return d[bit][num];
    d[bit][num]=0;
    for(int i = 0; i < n; i++){
        if(bit & (1 << i)) continue;
        d[bit][num] += solve(bit | (1 << i), (num * pow10[sz[i]] + v[i]) % k);
    }
    return d[bit][num];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    memset(d, -1, sizeof(d));
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        sz[i] = (int)s[i].size();
    }
    cin >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < sz[i]; j++) {
            v[i] = (v[i] * 10 + s[i][j] - '0') % k;
        }
    }
    pow10[0] = 1 % k;
    for(int i = 1; i <= 50; i++){
        pow10[i] = (pow10[i - 1] * 10) % k;
    }
    ll a = solve(0, 0);
    ll b = 1;
    for(int i = 2; i <= n; i++)
        b *= i;
    ll g = gcd(a, b);
    cout << a/g << "/" << b/g << "\n";
    
    return 0;
}
