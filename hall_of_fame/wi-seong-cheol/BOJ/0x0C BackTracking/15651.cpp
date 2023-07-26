//
//  15651.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 4 2
 [Output]
 1 1
 1 2
 1 3
 1 4
 2 1
 2 2
 2 3
 2 4
 3 1
 3 2
 3 3
 3 4
 4 1
 4 2
 4 3
 4 4
 */
// 시간복잡도: O(n^n)
// 최악시간: 823,543
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/15651

#include <iostream>

using namespace std;
int n, m;
int board[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << board[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        board[k] = i + 1;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    func(0);
    
    return 0;
}
