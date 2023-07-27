//
//  1974.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/19.
//

/*
 [Input]
 21
 [Output]
 50944540
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1974

#include <iostream>

using namespace std;
#define ll long long
const ll mod = 1e9;
int n;
ll d[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[2] = 1;
    for(int i = 3; i <= n; i++)
        d[i] = (d[i - 1] + d[i - 2]) * (i - 1) % mod;
    cout << d[n];
    
    return 0;
}
