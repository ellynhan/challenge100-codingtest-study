//
//  1213.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 ABACABA
 [Output]
 AABCBAA
 */
// 시간복잡도: O(n)
// 최악시간: 1,300
// 난이도: Silver 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1213

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string s, ans;
int chk[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    for(char ch: s)
        chk[ch - 'A']++;
    bool flag = false;
    
    if(s.size() % 2 == 0) {
        for(int i = 0; i < 26; i++) {
            if(chk[i] % 2 == 1) {
                flag = true;
                break;
            }
            for(int j = 0; j < chk[i] / 2; j++)
                ans += char('A' + i);
        }
        string tmp = ans;
        reverse(tmp.begin(), tmp.end());
        ans += tmp;
    } else {
        int cnt = 1;
        char middle = 'A';
        for(int i = 0; i < 26; i++) {
            if(chk[i] % 2 == 1) {
                if(cnt == 0) {
                    flag = true;
                    break;
                }
                middle += i;
                cnt--;
            }
            for(int j = 0; j < chk[i] / 2; j++)
                ans += char('A' + i);
        }
        string tmp = ans;
        reverse(tmp.begin(), tmp.end());
        ans += middle + tmp;
    }
    if(flag) cout << "I'm Sorry Hansoo";
    else cout << ans;
    
    return 0;
}
