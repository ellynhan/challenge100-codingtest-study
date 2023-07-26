//
//  2011.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 25114
 [Output]
 6
 */
// 시간복잡도: O(n)
// 최악시간: 5,000
// 난이도: Gold 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/2011

#include <iostream>

using namespace std;
const int mod = 1'000'000;
int n;
int a[5001];
int d[5001];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    n = (int)s.length();
    for(int i = 1; i <= n; i++)
        a[i] = s[i - 1] - '0';
    d[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(a[i] != 0) d[i] = d[i - 1];
        int x = a[i - 1] * 10 + a[i];
        if(9 < x && x < 27)
            d[i] = (d[i] + d[i - 2]) % mod;
    }
    cout << d[n];
    
    return 0;
}
