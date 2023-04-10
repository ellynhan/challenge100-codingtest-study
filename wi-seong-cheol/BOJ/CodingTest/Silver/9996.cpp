//
//  9996.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 3
 a*d
 abcd
 anestonestod
 facebook
 [Output]
 DA
 DA
 NE
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Silver 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/9996

#include <iostream>
#include <string>

using namespace std;
int n;
string pattern, target, s, e;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> pattern;
    for(int i = 0; i < pattern.size(); i++) {
        if(pattern[i] == '*') {
            s = pattern.substr(0, i);
            e = pattern.substr(i + 1, (int)pattern.size() - i);
            break;
        }
    }
    while(n--) {
        cin >> target;
        if(target.size() < s.size() + e.size()) {
            cout << "NE\n";
        } else if(target.substr(0, s.size()) == s &&
           target.substr(target.size() - e.size(), e.size()) == e) {
            cout << "DA\n";
        } else {
            cout << "NE\n";
        }
    }
    
    return 0;
}
