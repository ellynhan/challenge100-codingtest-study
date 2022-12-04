//
//  5397.cpp
//  main
//
//  Created by wi_seong on 2022/11/06.
//

/*
 [Input]
 2 
 <<BP<A>>Cd-
 ThIsIsS3Cr3t
 [Output]
 BAPC
 ThIsIsS3Cr3t
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 2
// Timer: 9m
// Url: https://www.acmicpc.net/problem/5397

#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        list<char> L;
        string s; cin >> s;
        auto cur = L.end();
        for(auto ch: s) {
            if(ch == '<') {
                if(cur != L.begin()) cur--;
            } else if(ch == '>') {
                if(cur != L.end()) cur++;
            } else if(ch == '-') {
                if(cur != L.begin()) {
                    cur--;
                    cur = L.erase(cur);
                }
            } else {
                L.insert(cur, ch);
            }
        }
        for(auto p: L) cout << p;
        cout << '\n';
    }
    
    return 0;
}
