//
//  9375.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 2
 3
 hat headgear
 sunglasses eyewear
 turban headgear
 3
 mask face
 sunglasses face
 makeup face
 [Output]
 5
 3
 */
// 시간복잡도: O(n)
// 최악시간: 30
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/9375

#include <iostream>
#include <map>

using namespace std;
int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> n;
        map<string, int> m;
        while(n--) {
            string s1, s2;
            cin >> s1 >> s2;
            if(m.find(s2) == m.end())
                m.insert({s2, 1});
            else
                m.at(s2)++;
        }
        int ans = 1;
        for(auto i : m)
            ans *= i.second + 1;
        ans -= 1;
        cout << ans << '\n';
    }
    
    return 0;
}
