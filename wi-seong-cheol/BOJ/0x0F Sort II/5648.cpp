//
//  5648.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/30.
//

/*
 [Input]
 10 5 2233
 1601 90100 13009 802
 50000000
 301 7654321
 210
 [Output]
 5
 5
 12
 103
 109
 208
 1061
 3322
 90031
 1234567
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Silver 4
// Timer: 5m
// Url: https://www.acmicpc.net/problem/5648

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long
int n;
string s;
vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        reverse(s.begin(), s.end());
        v.push_back(stoll(s));
    }
    sort(v.begin(), v.end());
    for(auto x: v)
        cout << x << '\n';
    
    return 0;
}
