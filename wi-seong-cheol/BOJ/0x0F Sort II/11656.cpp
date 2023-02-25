//
//  11656.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/30.
//

/*
 [Input]
 baekjoon
 [Output]
 aekjoon
 baekjoon
 ekjoon
 joon
 kjoon
 n
 on
 oon
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,500
// 난이도: Silver 4
// Timer: 5m
// Url: https://www.acmicpc.net/problem/11656

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
vector<string> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;
    for(int i = 0; i < int(s.length()); i++) {
        string sub = s.substr(i);
        v.push_back(sub);
    }
    sort(v.begin(), v.end());
    for(auto element: v)
        cout << element << '\n';
    
    return 0;
}
