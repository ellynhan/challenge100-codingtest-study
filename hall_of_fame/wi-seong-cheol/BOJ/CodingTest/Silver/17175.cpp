//
//  17175.cpp
//  main
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 50
 [Output]
 730021867
 */
// 시간복잡도: O(n)
// 최악시간: 50
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/17175

#include <iostream>

using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n;
ll d[51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[0] = 1; d[1] = 1;
    for(int i = 2; i <= n; i++)
        d[i] = (d[i - 1] + d[i - 2] + 1) % mod;
    cout << d[n];
    
    return 0;
}
