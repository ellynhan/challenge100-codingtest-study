//
//  2941.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/22.
//

/*
 [Input]
 ljes=njak
 [Output]
 6
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Silver 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/2941

#include <iostream>
#include <unordered_set>

using namespace std;
int ans;
string str, tmp;
unordered_set<string> S = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        tmp = str.substr(i, 2);
        if(S.find(tmp) != S.end()) {
            i++;
            ans++;
            continue;
        }
        tmp = str.substr(i, 3);
        if(S.find(tmp) != S.end()) {
            i += 2;
            ans++;
            continue;
        }
        if('a' <= str[i] && str[i] <= 'z')
            ans++;
    }
    cout << ans;
    
    return 0;
}
