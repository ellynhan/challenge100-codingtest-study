//
//  1157.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/24.
//

/*
 [Input]
 baaa
 [Output]
 A
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Bronze 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1157

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
map<char, int> m;
vector<pair<int, char>> v;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    for(char ch: s) {
        char c = ch > 'Z' ? ch - ('a' - 'A') : ch;
        m[c]++;
    }
    for(auto element: m)
        v.push_back({element.Y, element.X});
    sort(v.begin(), v.end(), greater<>());
    
    if(v.size() > 1 && v[0].X == v[1].X) cout << '?';
    else cout << v[0].Y;
    
    return 0;
}
