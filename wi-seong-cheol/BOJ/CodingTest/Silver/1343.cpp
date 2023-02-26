//
//  1343.cpp
//  main
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 XX.XXXXXXXXXX..XXXXXXXX...XXXXXX
 [Output]
 BB.AAAAAAAABB..AAAAAAAA...AAAABB
 */
// 시간복잡도: O(n)
// 최악시간: 50
// 난이도: Silver 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1343

#include <iostream>

using namespace std;
string s, ans;
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    s += '.';
    if(s[0] == 'X') cnt++;
    else ans += '.';
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == '.') {
            if(cnt == 2) {
                ans += "BB";
            }
            if(cnt % 2 == 1) {
                cout << -1;
                return 0;
            }
            ans += '.';
            cnt = 0;
        } else {
            cnt++;
            if(cnt == 4) {
                cnt = 0;
                ans += "AAAA";
            }
        }
    }
    ans.erase(ans.end() - 1);
    cout << ans;
    
    return 0;
}
