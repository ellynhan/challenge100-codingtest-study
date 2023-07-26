//
//  2138.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/07.
//

/*
 [Input]
 3
 000
 010
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 200,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2138

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;
int n;
int ans;
string s1, s2, tmp;
int cnt1, cnt2;

void pushSwitch(string& s, int idx) {
    if(idx == 0) {
        s[idx] = (s[idx] == '1') ? '0' : '1';
        s[idx + 1] = (s[idx + 1] == '1') ? '0' : '1';
    } else if(idx == n - 1) {
        s[idx] = (s[idx] == '1') ? '0' : '1';
        s[idx - 1] = (s[idx - 1] == '1') ? '0' : '1';
    } else {
        s[idx] = (s[idx] == '1') ? '0' : '1';
        s[idx + 1] = (s[idx + 1] == '1') ? '0' : '1';
        s[idx - 1] = (s[idx - 1] == '1') ? '0' : '1';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s1 >> s2;
    tmp = s1;
    // 0번째 스위치를 안 눌렀을 때
    for(int i = 1; i < n; i++) {
        if(s1[i - 1] != s2[i - 1]) {
            pushSwitch(s1, i);
            cnt1++;
        }
    }
    if(s1 != s2) cnt1 = INF;
    
    s1 = tmp;
    pushSwitch(s1, 0);
    cnt2 = 1;
    // 0번째 스위치를 눌렀을 때
    for(int i = 1; i < n; i++) {
        if(s1[i - 1] != s2[i - 1]) {
            pushSwitch(s1, i);
            cnt2++;
        }
    }
    if(s1 != s2) cnt2 = INF;
    
    ans = min(cnt1, cnt2);
    if(ans == INF) cout << -1;
    else cout << ans;
    
    return 0;
}
