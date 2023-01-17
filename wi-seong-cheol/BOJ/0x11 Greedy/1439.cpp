//
//  1439.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 11001100110011000001
 [Output]
 4
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1439

#include <iostream>
#include <algorithm>

using namespace std;
int len;
int cnt[2];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    len = (int)s.length();
    cnt[s[0] - '0']++;
    for(int i = 1; i < len; i++)
        if(s[i] != s[i-1])
            cnt[s[i] - '0']++;
    cout << *min_element(cnt, cnt + 2);
    
    return 0;
}
