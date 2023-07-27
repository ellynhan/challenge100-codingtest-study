//
//  15624.cpp
//  main
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 1000000
 [Output]
 918091266
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/15624

#include <iostream>

using namespace std;
#define ll long long
const int SIZE = 1'000'001;
const int mod = 1e9 + 7;
int n;
ll d[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[0] = 0; d[1] = 1;
    for(int i = 2; i <= n; i++)
        d[i] = (d[i - 1] + d[i - 2]) % mod;
    cout << d[n];
    
    return 0;
}
