//
//  7785.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4
 Baha enter
 Askar enter
 Baha leave
 Artem enter
 [Output]
 Askar
 Artem
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/7785

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
int n;
unordered_set<string> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        string s1, s2;
        cin >> s1 >> s2;
        if(s2 == "enter") {
            s.insert(s1);
        } else {
            s.erase(s.find(s1));
        }
    }
    vector<string> v(s.begin(), s.end());
    sort(v.begin(), v.end(), greater<string>());
    for(auto element: v) {
        cout << element << '\n';
    }
    
    return 0;
}
