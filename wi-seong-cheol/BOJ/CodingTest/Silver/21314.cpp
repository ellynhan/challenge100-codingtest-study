//
//  21314.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/13.
//

/*
 [Input]
 MMMMMMMMMMMKKKKKKKKKKK
 [Output]
 5000000000005555555555
 1000000000055555555555
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 9,000,000
// 난이도: Silver 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/21314

#include <iostream>

using namespace std;
string s;
string mn, mx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    int cnt = 0;
    for(char c: s) {
        if(c == 'M') cnt++;
        else {
            if(cnt > 0) {
                mn += '1';
                mx += '5';
                for(int i = 0; i < cnt - 1; i++) {
                    mn += '0';
                    mx += '0';
                }
                mn += '5';
                mx += '0';
            } else {
                mn += '5';
                mx += '5';
            }
            cnt = 0;
        }
    }
    if(cnt > 0) {
        mn += '1';
        for(int i = 0; i < cnt - 1; i++)
            mn += '0';
        for(int i = 0; i < cnt; i++)
            mx += '1';
    }
    cout << mx << '\n' << mn;
    
    return 0;
}
