//
//  19637.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/07.
//

/*
 [Input]
 3 8
 WEAK 10000
 NORMAL 100000
 STRONG 1000000
 0
 9999
 10000
 10001
 50000
 100000
 500000
 1000000
 [Output]
 WEAK
 WEAK
 WEAK
 NORMAL
 NORMAL
 NORMAL
 STRONG
 STRONG
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/≈

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
int n, m;
string s; int x;
map<int, string> style;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s >> x;
        style.insert({x, s});
    }
    while(m--) {
        cin >> x;
        cout << style.lower_bound(x) -> second << '\n';
    }
    
    return 0;
}
