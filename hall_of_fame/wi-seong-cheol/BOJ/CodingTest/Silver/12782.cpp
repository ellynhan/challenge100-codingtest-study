//
//  12782.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/24.
//

/*
 [Input]
 3
 1011 1100
 100101 110100
 00110100 10010111
 [Output]
 2
 1
 3
 */
// 시간복잡도: O(n)
// 최악시간: 50,000,000
// 난이도: Silver 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/12782

#include <iostream>
#include <algorithm>

using namespace std;
int t, ans, dif;
string a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> a >> b;
        int a_cnt_1, b_cnt_1;
        a_cnt_1 = b_cnt_1 = 0;
        ans = dif = 0;
        for(char ch: a)
            a_cnt_1 += ch - '0';
        for(char ch: b)
            b_cnt_1 += ch - '0';
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == b[i]) continue;
            dif++;
        }
        ans += abs(a_cnt_1 - b_cnt_1);
        dif -= ans;
        ans += dif / 2;
        cout << ans << '\n';
    }
    
    return 0;
}
