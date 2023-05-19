//
//  2195.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/23.
//

/*
 [Input]
 aababcefcefd
 aabcefd
 [Output]
 2
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2195

#include <iostream>
#include <algorithm>

using namespace std;
string s1, s2;
int cnt, mx_len;
int len1, len2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s1 >> s2;
    len1 = (int)s1.length();
    len2 = (int)s2.length();
    for(int i = 0; i < len2;) {
        mx_len = 0;
        for(int j = 0; j < len1; j++) {
            int len = 0;
            while(s1[j + len] == s2[i + len])
                len++;
            mx_len = max(mx_len, len);
        }
        i += mx_len;
        cnt++;
    }
    cout << cnt;
    
    return 0;
}
