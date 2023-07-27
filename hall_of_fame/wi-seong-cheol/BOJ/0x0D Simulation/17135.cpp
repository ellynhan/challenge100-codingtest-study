//
//  17135.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 5 5 1
 0 0 0 0 0
 0 0 0 0 0
 0 0 0 0 0
 0 0 0 0 0
 1 1 1 1 1
 [Output]
 3
 */
// 시간복잡도: O(n ^ 6)
// 최악시간: 11,390,625
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17135

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
#define X first
#define Y second
int n, m, d, ans;
int board[16][16];
int a[16][16]; // 시뮬레이션을 돌릴 때 사용하는 격자판
int enemy;
vector<pair<int, int>> epos;

int dist(int i, int j, int arow, int acol) {
    return abs(i - arow) + abs(j - acol);
}

void shoot(int arow, int x, int y, int z) {
    epos.clear();
        
    for(int acol: {x, y, z}) {
        vector<tuple<int, int, int>> cand;
        for(int i = 0; i < arow; i++)
            for(int j = 0; j < m; j++)
                if(a[i][j] && dist(i, j, arow, acol) <= d)
                    cand.push_back({dist(i, j, arow, acol), j, i});
        
        if(!cand.empty()) {
            sort(cand.begin(), cand.end());
            int dd, yy, xx;
            tie(dd, yy, xx) = cand[0];
            epos.push_back({xx, yy});
        }
    }
}

int solve(int x, int y, int z) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            a[i][j] = board[i][j];
    
    int ret = 0;
    int arow = n;
    int e = enemy;
    
    while(e) {
        shoot(arow, x, y, z);
        for(auto cur: epos) {
            int xx = cur.X;
            int yy = cur.Y;
            if(a[xx][yy]) {
                a[xx][yy] = 0;
                e--;
                ret++;
            }
        }
        
        for(int col = 0; col < m; col++)
            if(a[arow - 1][col]) {
                a[arow - 1][col] = 0;
                e--;
            }
        arow--;
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> d;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j]) enemy++;
        }
    
    for(int i = 0; i < m; i++)
        for(int j = i + 1; j < m; j++)
            for(int k = j + 1; k < m; k++)
                ans = max(ans, solve(i, j, k));
    
    cout << ans;
    
    return 0;
}
