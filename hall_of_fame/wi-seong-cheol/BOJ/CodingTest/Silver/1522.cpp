//
//  1522.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 abababababababa
 [Output]
 3
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Silver 1
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1522

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;
int cnt;
int ans = INF;
string s;

int solve(string& s, int x, int len) {
    int ret = 0;
    for(int i = x; i < x + len; i++)
        if(s[(i + 1) % s.length()] == 'a')
            ret++;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    for(int i = 0; i < s.length(); i++)
        if(s[i] == 'b') cnt++;
    for(int i = 0; i < s.length(); i++)
        ans = min(ans, solve(s, i, cnt));
    cout << ans;
    
    return 0;
}
