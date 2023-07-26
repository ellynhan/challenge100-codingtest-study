//
//  19939.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/16.
//

/*
 [Input]
 10 3
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/19939

#include <iostream>

using namespace std;
int n, k;

int sum(int x) {
    if(x == 1) return 1;
    return x + sum(x - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    int s = sum(k);
    if(s > n) cout << -1;
    else cout << k - 1 + ((n - s) % k != 0);
    
    return 0;
}
