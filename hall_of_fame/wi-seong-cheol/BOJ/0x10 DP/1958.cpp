//
//  1958.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/16.
//

/*
 [Input]
 abcdefghijklmn
 bdefg
 efg
 [Output]
 3
 */
// 시간복잡도: O(nmk)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1958

#include <iostream>
#include <algorithm>

using namespace std;
int d[101][101][101];
string s1, s2, s3;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2 >> s3;
    for(int i = 1; s1[i - 1]; i++) {
        for(int j = 1; s2[j - 1]; j++) {
            for(int k = 1; s3[k - 1]; k++) {
                int val = 0;
                if(s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) val = 1;
                d[i][j][k] = max({
                    d[i - 1][j][k], d[i][j - 1][k], d[i][j][k - 1],
                    d[i - 1][j - 1][k], d[i - 1][j][k - 1], d[i][j - 1][k - 1],
                    d[i - 1][j - 1][k - 1] + val});
            }
        }
    }
    cout << d[s1.size()][s2.size()][s3.size()];
    
    return 0;
}

