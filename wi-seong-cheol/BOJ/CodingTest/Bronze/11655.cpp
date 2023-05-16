//
//  11655.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/24.
//

/*
 [Input]
 221 231
 [Output]
 132
 */
// 시간복잡도: O(len(n))
// 최악시간: 6
// 난이도: Bronze 2
// Timer: 5m
// Url: https://www.acmicpc.net/problem/11655

#include <iostream>

using namespace std;
string s1, s2;
int a, b;

int s2i(string s) {
    int ret = 0;
    
    while(!s.empty()) {
        ret *= 10;
        ret += s.back() - '0';
        s.pop_back();
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s1 >> s2;
    a = s2i(s1);
    b = s2i(s2);
    
    if(a < b) cout << b;
    else cout << a;
    
    return 0;
}
