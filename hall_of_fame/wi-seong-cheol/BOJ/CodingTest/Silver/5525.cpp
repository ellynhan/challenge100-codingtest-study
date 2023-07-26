//
//  5525.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/24.
//

/*
 [Input]
 1
 13
 OOIOIOIOIIOII
 [Output]
 4
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/5525

#include <iostream>

using namespace std;
int n, m, ans, cnt;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> s;
    for(int i = 1; i < m - 1; i++) {
        if(s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
            cnt++;
            if(cnt == n) {
                ans++;
                cnt--;
            }
            i++;
        } else {
            cnt = 0;
        }
    }
    
    cout << ans;
    
    return 0;
}
