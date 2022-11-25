//
//  1874.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/07.
//

/*
 [Input]
 8
 4
 3
 6
 8
 7
 5
 2
 1
 [Output]
 +
 +
 +
 +
 -
 -
 +
 +
 -
 +
 +
 -
 -
 -
 -
 -
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 2
// Timer: 34m
// Url: https://www.acmicpc.net/problem/1874

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    stack<int> S;
    string ans;
    int cnt = 1;
    
    while(n--) {
        int x; cin >> x;
        
        while(cnt <= x) {
            S.push(cnt++);
            ans += '+';
        }
        if(S.top() == x) {
            S.pop();
            ans += '-';
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    for(auto ch: ans)
        cout << ch << '\n';
    return 0;
}
