//
//  4949.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

/*
 [Input]
 So when I die (the [first] I will see in (heaven) is a score list).
 [ first in ] ( first out ).
 Half Moon tonight (At least it is better than no Moon at all].
 A rope may form )( a trail in a maze.
 Help( I[m being held prisoner in a fortune cookie factory)].
 ([ (([( [ ] ) ( ) (( ))] )) ]).
  .
 .
 [Output]
 yes
 yes
 no
 no
 no
 yes
 yes
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Silver 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/4949

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        string s; getline(cin, s);
        if(s == ".") break;
        stack<char> S;
        for(auto ch: s) {
            if(ch == '[' || ch == '(') {
                S.push(ch);
            } else if((ch == ']' || ch == ')') && S.empty()) {
                S.push(ch);
                break;
            } else if(ch == ']') {
                if(S.top() == '[') S.pop();
                else break;
            } else if(ch == ')') {
                if(S.top() == '(') S.pop();
                else break;
            }
        }
        if(!S.empty()) cout << "no\n";
        else cout << "yes\n";
    }
    
    return 0;
}
