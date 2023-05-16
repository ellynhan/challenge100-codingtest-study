//
//  14620.cpp
//  main
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 6
 1 0 2 3 3 4
 1 1 1 1 1 1
 0 0 1 1 1 1
 3 9 9 0 1 99
 9 11 3 1 0 3
 12 3 0 0 0 1
 [Output]
 12
 */
// 시간복잡도: O(nC3)
// 최악시간: 400,800
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14620

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;
int n, ans = INF;
int board[11][11];
bool vis[11][11];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int price(int x, int y) {
    int sum = board[x][y];
    vis[x][y] = true;

    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny) || vis[nx][ny]) return -1;
        vis[nx][ny] = true;
        sum += board[nx][ny];
    }
    
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    
    vector<int> brute(n * n);
    fill(brute.begin() + 3, brute.end(), 1);
    do {
        bool flag = false;
        int sum = 0;
        for(int i = 0; i < n; i++)
            fill(vis[i], vis[i] + n, false);
        
        for(int i = 0; i < n * n; i++)
            if(!brute[i]) {
                int p = price(i / n, i % n);
                if(p == -1) {
                    flag = true;
                    break;
                }
                sum += p;
            }
        
        if(flag) continue;
        ans = min(ans, sum);
    } while(next_permutation(brute.begin(), brute.end()));
    cout << ans;
    
    return 0;
}
