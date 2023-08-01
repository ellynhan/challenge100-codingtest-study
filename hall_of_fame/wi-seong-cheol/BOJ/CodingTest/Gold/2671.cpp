//
//  2671.cpp
//  main
//
//  Created by wi_seong on 2023/03/23.
//

/*
 [Input]
 10010111
 [Output]
 NOISE
 */
// 시간복잡도: O(n)
// 최악시간: 150
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2671

#include <iostream>
#include <regex>
#include <string>

using namespace std;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> s;
    regex pattern("(100+1+|01)+");
    smatch match;
    
    if(regex_match(s, match, pattern)) {
        cout << "SUBMARINE" << '\n';
    } else {
        cout << "NOISE" << '\n';
    }
    
    return 0;
}
