//
//  1541.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 55-50+40
 [Output]
 -35
 */
// 시간복잡도: O(n)
// 최악시간: 50
// 난이도: Silver 2
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1541

#include <iostream>

using namespace std;
int tmp, ans;
int sign = 1;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(char c : s) {
        if(c == '+' || c == '-') {
            ans += tmp * sign;
            if(c == '-') sign = -1;
            tmp = 0;
        } else {
            tmp *= 10;
            tmp += c - '0';
        }
    }
    ans += tmp * sign;
    cout << ans;
    
    return 0;
}
