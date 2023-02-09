//
//  6550.cpp
//  main
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 sequence subsequence
 person compression
 VERDI vivaVittorioEmanueleReDiItalia
 caseDoesMatter CaseDoesMatter
 [Output]
 Yes
 No
 Yes
 No
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/6550

#include <iostream>

using namespace std;
string s, t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> s >> t) {
        int idx = 0;
        for(char c: t)
            if(c == s[idx]) idx++;
        if(idx == s.size()) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}

