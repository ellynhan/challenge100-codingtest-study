//
//  11478.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 ababc
 [Output]
 12
 */
// 시간복잡도: O(n^2)
// 최악시간: 1,000,000
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11478

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
string str;
unordered_set<string> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str;
    for(int i = 1; i <= str.size(); i++) {
        for(int j = 0; j < str.size(); j++) {
            string tmp = str.substr(j, i);
            s.insert(tmp);
        }
    }
    cout << s.size();
    
    return 0;
}
