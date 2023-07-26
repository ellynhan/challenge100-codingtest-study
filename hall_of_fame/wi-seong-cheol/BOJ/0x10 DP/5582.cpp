//
//  5582.cpp
//  main
//
//  Created by wi_seong on 2023/01/15.
//

/*
 [Input]
 ABRACADABRA
 ECADADABRBCRDARA
 [Output]
 5
 */
// 시간복잡도: O(nm)
// 최악시간: 16,000,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/5582

#include <iostream>
#include <algorithm>

using namespace std;
int ans;
int d[4001][4001];
string s1, s2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++) {
        for(int j = 0; j < s2.size(); j++) {
            if(s1[i] == s2[j]) {
                if(i == 0 || j == 0) d[i][j] = 1;
                else d[i][j] = d[i - 1][j - 1] + 1;
                ans = max(ans, d[i][j]);
            }
        }
    }
    cout << ans;
    
    return 0;
}
