//
//  22223.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 5 2
 map
 set
 dijkstra
 floyd
 os
 map,dijkstra
 map,floyd
 [Output]
 3
 2
 */
// 시간복잡도: O(n)
// 최악시간: 2,000,000
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/22223

#include <iostream>
#include <sstream>
#include <unordered_set>

using namespace std;
int n, m;
string s;
unordered_set<string> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(n--) {
        cin >> s;
        S.insert(s);
    }
    while(m--) {
        cin >> s;
        stringstream ss(s);
        string token;
        while(getline(ss, token, ',')) {
            if(S.find(token) != S.end()) {
                S.erase(token);
            }
        }
        cout << S.size() << '\n';
    }
    
    return 0;
}
