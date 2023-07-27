//
//  1316.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/22.
//

/*
 [Input]
 3
 happy
 new
 year
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Silver 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1316

#include <iostream>

using namespace std;
string s;
int n, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        cin >> s;
        int chk[26] = {0};
        bool flag = true;
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == s[i + 1]) continue;
            if(chk[s[i] - 'a'] != 0) {
                flag = false;
                break;
            }
            chk[s[i] - 'a']++;
        }
        if(!chk[s.back() - 'a'] && flag)
            ans++;
    }
    cout << ans;
    
    return 0;
}
