//
//  9251.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 ACAYKP
 CAPCAK
 [Output]
 4
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/9251

#include <iostream>
#include <algorithm>

using namespace std;
char s1[1002], s2[1002];
int d[1001][1001], i, j;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> (s1 + 1) >> (s2 + 1);
    for(i = 1; s1[i]; i++)
        for(j = 1; s2[j]; j++)
            d[i][j] = max({d[i][j - 1], d[i - 1][j], d[i - 1][j - 1] + (s1[i] == s2[j])});

    cout << d[i - 1][j - 1];
    
    return 0;
}
