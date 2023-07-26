//
//  13549.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 5 17
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Gold 5
// Timer: 25m
// Url: https://www.acmicpc.net/problem/13549

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
const int SIZE = 100001;
int n, m;
int board[SIZE];
queue<int> Q;

bool OOB(int x) { return x < 0 || x >= SIZE; }

void teleport(int x) {
    int tmp = x;
    if(!tmp) return;
    while(tmp < SIZE && !board[m]) {
        if(!board[tmp]) {
            board[tmp] = board[x];
            Q.push(tmp);
            if(tmp == m) return;
        }
        tmp <<= 1;
    }
}

void bfs() {
    Q.push(n);
    board[n] = 1;
    teleport(n);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur == m) break;
        for(int nx: {cur + 1, cur - 1}) {
            if(OOB(nx) || board[nx]) continue;
            board[nx] = board[cur] + 1;
            teleport(nx);
            Q.push(nx);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    bfs();
    cout << board[m] - 1;
    
    return 0;
}
