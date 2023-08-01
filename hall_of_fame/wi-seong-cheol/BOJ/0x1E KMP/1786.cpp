//
//  1786.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 ABC ABCDAB ABCDABCDABDE
 ABCDABD
 [Output]
 16
 */
// 시간복잡도: O(n + m)
// 최악시간: 2,000,000
// 난이도: Platinum 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1786

#include <iostream>
#include <vector>

using namespace std;
string t, p;
vector<int> f;
vector<int> pos;

vector<int> failure() {
    vector<int> f(p.size());
    int j = 0;
    for(int i = 1; i < p.size(); i++) {
        while(j > 0 && p[i] != p[j]) j = f[j - 1];
        if(p[i] == p[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    getline(cin, t);
    getline(cin, p);
    f = failure();
    int j = 0;
    for(int i = 0; i < t.size(); i++) {
        while(j > 0 && t[i] != p[j]) j = f[j - 1];
        if(t[i] == p[j]) j++;
        if(j == p.size()) {
            pos.push_back(i - j + 1);
            j = f[j - 1];
        }
    }
    cout << pos.size() << '\n';
    for(int x: pos) cout << x + 1 << ' ';
    
    return 0;
}
