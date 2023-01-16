//
//  9252.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/16.
//

/*
 [Input]
 ACAYKP
 CAPCAK
 [Output]
 4
 ACAK
 */
// 시간복잡도: O(n*m)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/9252

#include <iostream>
#include <algorithm>

using namespace std;
string s1, s2;
int d[1001][1001];
int len1, len2;

void print(int i, int j) {
    if(d[i][j] == 0) return;
    if(s1[i - 1] == s2[j - 1]) {
        print(i - 1, j - 1);
        cout << s1[i - 1];
    } else {
        if(d[i - 1][j] > d[i][j - 1])
            print(i - 1, j);
        else
            print(i, j - 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s1 >> s2;
    len1 = (int)s1.length();
    len2 = (int)s2.length();
    for(int i = 1; s1[i - 1]; i++) {
        for(int j = 1; s2[j - 1]; j++) {
            d[i][j] = max({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1])});
        }
    }
    cout << d[len1][len2] << '\n';
    print(len1, len2);
    
    return 0;
}

