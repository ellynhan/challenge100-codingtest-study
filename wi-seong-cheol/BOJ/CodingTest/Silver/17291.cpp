//
//  17291.cpp
//  main
//
//  Created by wi_seong on 2023/02/11.
//

/*
 [Input]
 20
 [Output]
 181657
 */
// 시간복잡도: O(n)
// 최악시간: 20
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/17291

#include <iostream>

using namespace std;
int n;
int d[21];
int die[21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[1] = 1; die[4] = 1;
    for(int i = 2; i <= n; i++) {
        d[i] = d[i - 1] * 2;
        d[i] -= die[i];
        if(i % 2 == 0) die[i + 4] += d[i - 1];
        else die[i + 3] += d[i - 1];
    }
    cout << d[n];
    
    return 0;
}
