//
//  20365.cpp
//  main
//
//  Created by wi_seong on 2023/02/11.
//

/*
 [Input]
 6
 RBBBBR
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/20365

#include <iostream>
#include <algorithm>

using namespace std;
string s;
int n, cntR, cntB;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++) {
        if(i == 0)
            s[i] == 'R' ? cntR++ : cntB++;
        else if(s[i] != s[i - 1])
            s[i] == 'R' ? cntR++ : cntB++;
    }
        
    cout << min(cntB, cntR) + 1;
    
    return 0;
}
