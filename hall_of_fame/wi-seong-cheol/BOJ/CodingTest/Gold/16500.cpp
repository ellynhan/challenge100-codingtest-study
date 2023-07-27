//
//  16500.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 softwarecontest
 2
 software
 contest
 [Output]
 1
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/16500

#include <iostream>
#include <string>

using namespace std;
int n, len;
int d[101];
string s, a[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s >> n;
    len = (int)s.length();
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        string tmp = s.substr(0, (int)a[i].length());
        if(tmp == a[i])
            d[a[i].size() - 1] = 1;
    }
    
    for(int i = 0; i < len - 1; i++) {
        if(d[i] == 0) continue;
        for(string str: a) {
            string tmp = s.substr(i + 1, (int)str.length());
            if(tmp == str)
                d[i + str.size()] = 1;
        }
    }
    cout << d[len - 1];
    
    return 0;
}
