//
//  1074.cpp
//  main
//
//  Created by wi_seong on 2022/11/21.
//

/*
 [Input]
 2 3 1
 [Output]
 11
 */
// 시간복잡도: O(n)
// 최악시간: 15
// 난이도: Silver 1
// Timer: 12m
// Url: https://www.acmicpc.net/problem/1074

#include <iostream>

using namespace std;

int func(int n, int r, int c) {
    if(n == 0) return 0;
    int half = 1 << (n - 1);
    if(r < half && c < half) return func(n - 1, r, c);
    else if(r < half && c >= half) return half * half + func(n - 1, r, c - half);
    else if(r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);
    else return 3 * half * half + func(n - 1, r - half, c - half);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
    
    return 0;
}
