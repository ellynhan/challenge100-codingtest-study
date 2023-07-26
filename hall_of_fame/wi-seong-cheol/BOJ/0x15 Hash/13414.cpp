//
//  13414.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3 8
 20103324
 20133221
 20133221
 20093778
 20140101
 01234567
 20093778
 20103325
 [Output]
 20103324
 20133221
 20140101
 */
// 시간복잡도: O(nlogn)
// 최악시간: 2,500,000
// 난이도: Silver 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/13414

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, k;
unordered_map<string, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    for(int i = 0; i < n; i++) {
        string x; cin >> x;
        if(m.find(x) == m.end())
            m.insert({x, i});
        else
            m.at(x) = i;
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.Y < b.Y;});
    int en = min(k, (int)v.size());
    for(int i = 0; i < en; i++)
        cout << v[i].X << '\n';
    
    return 0;
}
