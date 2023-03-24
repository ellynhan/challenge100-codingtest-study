//
//  2675.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/24.
//

/*
 [Input]
 2
 3 ABC
 5 /HTP
 [Output]
 AAABBBCCC
 /////HHHHHTTTTTPPPPP
 */
// 시간복잡도: O(r * len(s))
// 최악시간: 160,000
// 난이도: Bronze 2
// Timer: 5m
// Url: https://www.acmicpc.net/problem/2675

#include <iostream>

using namespace std;
int t, r;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> r >> s;
        string ans = "";
        for(char ch: s) {
            for(int i = 0; i < r; i++)
                ans += ch;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
