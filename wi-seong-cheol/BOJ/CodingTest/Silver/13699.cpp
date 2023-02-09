//
//  13699.cpp
//  main
//
//  Created by wi_seong on 2023/02/08.
//

/*
 [Input]
 25
 [Output]
 4861946401452
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 35
// 난이도: Silver 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/13699

#include <iostream>

using namespace std;
#define ll long long
int n;
ll d[36];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            d[i] += d[j] * d[i - j - 1];
        }
    }
    cout << d[n];
    
    return 0;
}
