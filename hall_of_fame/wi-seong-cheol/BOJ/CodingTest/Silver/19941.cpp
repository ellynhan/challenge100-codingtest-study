//
//  19941.cpp
//  main
//
//  Created by wi_seong on 2023/04/06.
//

/*
 [Input]
 20 1
 HHPHPPHHPPHPPPHPHPHP
 [Output]
 8
 */
// 시간복잡도: O(n * k)
// 최악시간: 200,000
// 난이도: Silver 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/19941

#include <iostream>

using namespace std;
int ans;
int n, m;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'P') {
            int st = (i - m) < 0 ? 0 : i - m;
            int en = (i + m) > n ? n : i + m + 1;
            for(; st < en; st++) {
                if(st == i) continue;
                if(s[st] == 'H') {
                    ans++;
                    s[st] = '.';
                    break;
                }
            }
        }
    }
    cout << ans;
    
    return 0;
}
