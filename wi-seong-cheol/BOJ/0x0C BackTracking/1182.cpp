//
//  1182.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 5 0
 -7 -3 -2 5 8
 [Output]
 1
 */
// 시간복잡도: O(2^n)
// 최악시간: 1,048,576
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1182

#include <iostream>

using namespace std;
int ans, n, s;
int board[21];
bool isused[21];

void func(int k, int total) {
    if(k == n) {
        if(total == s) ans++;
        return;
    }
    func(k + 1, total);
    func(k + 1, total + board[k]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    func(0, 0);
    if(s == 0) ans--;
    cout << ans;
    
    return 0;
}
