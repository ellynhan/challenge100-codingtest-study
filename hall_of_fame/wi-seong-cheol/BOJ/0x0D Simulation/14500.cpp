//
//  14500.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 5 5
 1 2 3 4 5
 5 4 3 2 1
 2 3 4 5 6
 6 5 4 3 2
 1 2 1 2 1
 [Output]
 19
 */
// 시간복잡도: O(n * m)
// 최악시간: 2,500
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/14500

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
int n, m, ans;
int board[501][501];
vector<vector<pair<int,int>>> tetro;

bool isadj(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.X == b.X) return abs(a.Y - b.Y) == 1;
    if(a.Y == b.Y) return abs(a.X - b.X) == 1;
    return false;
}

bool isConnection(const vector<pair<int, int>>& shape) {
    bool flag = false;
    for(int i = 0; i < 4; i++) {
        int cnt = 0;
        for(int j = 0; j < 4; j++) {
            if(isadj(shape[i], shape[j]))
                cnt++;
        }
        if(cnt == 0) return false;
        if(cnt >= 2) flag = true;
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    vector<int> brute(16);
    fill(brute.begin() + 12, brute.end(), 1);
    do {
        vector<pair<int, int>> shape;
        for(int i = 0; i < 16; i++) {
            if(brute[i] == 1)
                shape.push_back({i / 4, i % 4});
        }
        if(isConnection(shape)) tetro.push_back(shape);
    } while(next_permutation(brute.begin(), brute.end()));
    
    for(int i = 0; i <= n - 4; i++) {
        for(int j = 0; j <= m - 4; j++) {
            for(auto shape: tetro) {
                int tot = 0;
                for(auto coor : shape)
                    tot += board[i + coor.X][j + coor.Y];
                ans = max(ans, tot);
            }
        }
    }
    cout << ans;
    
    return 0;
}
