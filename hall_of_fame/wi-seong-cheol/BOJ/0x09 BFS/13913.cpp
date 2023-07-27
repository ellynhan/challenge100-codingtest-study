//
//  13913.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 5 17
 [Output]
 4
 5 4 8 16 17
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/13913

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int MX = 200000;
int n, k;
vector<int> ans;
int board[MX + 1];

void bfs() {
    queue<int> Q;
    Q.push(n);
    board[n] = 0;
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        if(x == k) break;
        for(int nxt: {x - 1, x + 1, 2 * x}) {
            if(nxt < 0 || nxt >= MX) continue;
            if(board[nxt] != -1) continue;
            board[nxt] = x;
            Q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    fill(board, board + MX, -1);
    bfs();
    int nxt = k;
    while(nxt != n) {
        ans.push_back(nxt);
        nxt = board[nxt];
    }
    ans.push_back(n);
    reverse(ans.begin(), ans.end());
    cout << ans.size() - 1 << '\n';
    for(int x: ans)
        cout << x << ' ';
    
    return 0;
}
