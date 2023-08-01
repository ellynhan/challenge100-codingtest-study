//
//  15652.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 3 1
 [Output]
 1
 2
 3
 */
// 시간복잡도: O(n!)
// 최악시간: 40320
// 난이도: Silver 3
// Timer: 5m
// Url: https://www.acmicpc.net/problem/15652

#include <iostream>

using namespace std;
int n, m;
int board[10];

void func(int k, int st) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << board[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = st; i < n; i++) {
        board[k] = i + 1;
        func(k + 1, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    func(0, 0);
    
    return 0;
}
