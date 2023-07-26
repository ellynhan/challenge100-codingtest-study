//
//  20920.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/09.
//

/*
 [Input]
 7 4
 apple
 ant
 sand
 apple
 append
 sand
 sand
 [Output]
 sand
 apple
 append
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/20920

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define str first
#define cnt second
int n, m;
string s;
map<string, int> M;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    if(a.cnt == b.cnt) {
        if(a.str.length() == b.str.length())
            for(int i = 0; i < a.str.length(); i++)
                if(a.str[i] != b.str[i])
                    return a.str[i] < b.str[i];
        return a.str.length() > b.str.length();
    }
    return a.cnt > b.cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(n--) {
        cin >> s;
        if(s.length() >= m)
            M[s]++;
    }
    vector<pair<string, int>> v(M.begin(), M.end());
    sort(v.begin(), v.end(), cmp);
    for(auto element: v)
        cout << element.str << '\n';
    
    return 0;
}
