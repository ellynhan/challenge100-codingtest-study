//
//  1759.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 4 6
 a t c i s w
 [Output]
 acis
 acit
 aciw
 acst
 acsw
 actw
 aist
 aisw
 aitw
 astw
 cist
 cisw
 citw
 istw
 */
// 시간복잡도: O(n!)
// 최악시간: 1.3076744e+12
// 난이도: Gold 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1759

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
char board[16];
bool isused[16];

void func(int k, int st, int cnt) {
    if(k == m && cnt > 0 && m - cnt > 1) {
        for(int i = 0; i < n; i++)
            if(isused[i])
                cout << board[i];
        cout << '\n';
        return;
    }
    for(int i = st; i < n; i++) {
        if(!isused[i]) {
            isused[i] = true;
            if(board[i] == 'a' || board[i] == 'e' || board[i] == 'i' || board[i] == 'o' || board[i] == 'u') {
                func(k + 1, i + 1, cnt + 1);
            } else {
                func(k + 1, i + 1, cnt);
            }
            isused[i] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    sort(board, board + n);
    func(0, 0, 0);
    
    return 0;
}
