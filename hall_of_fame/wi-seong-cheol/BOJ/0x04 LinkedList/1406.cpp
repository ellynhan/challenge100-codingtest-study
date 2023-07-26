//
//  1406.cpp
//  main
//
//  Created by wi_seong on 2022/11/06.
//

/*
 [Input]
 abcd
 3
 P x
 L
 P y
 [Output]
 abcdyx
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Silver 2
// Timer: 23m
// Url: https://www.acmicpc.net/problem/1406

#include <iostream>
#include <string>
#include <list>

using namespace std;
int n;
string s;
list<char> L;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
         
    cin >> s >> n;
    for(int i = 0; i < s.size(); i++)
        L.insert(L.end(), s[i]);
    auto cur = L.end();
    while(n--) {
        char op; cin >> op;
        if(op == 'L') {
            if(cur != L.begin()) cur--;
        } else if(op == 'D') {
            if(cur != L.end()) cur++;
        } else if(op == 'B') {
            if(cur != L.begin()) {
                cur--;
                cur = L.erase(cur);
            }
        } else {
            char ch; cin >> ch;
            L.insert(cur, ch);
        }
    }
    for(auto ch: L)
        cout << ch;
    
    return 0;
}
