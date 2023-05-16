//
//  20310.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 000011
 [Output]
 001
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/20310

#include <iostream>
#include <string>

using namespace std;
string s, ans;
int cnt[2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    for(char ch: s)
        cnt[ch - '0']++;
    int cnt0 = cnt[0] / 2;
    int cnt1 = cnt[1] / 2;
    for(int i = (int)s.size() - 1; i >= 0; i--)
        if(cnt0 > 0 && s[i] == '0') {
            cnt0--;
            s.erase(s.begin() + i);
        }
    for(int i = 0; i < s.size(); i++)
        if(cnt1 > 0 && s[i] == '1') {
            cnt1--;
            s.erase(s.begin() + i--);
        }
    cout << s;
    
    return 0;
}
