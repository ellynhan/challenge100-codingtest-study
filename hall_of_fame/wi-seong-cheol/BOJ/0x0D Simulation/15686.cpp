//
//  15686.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 5 3
 0 0 1 0 0
 0 0 2 0 1
 0 1 2 0 0
 0 0 1 0 0
 0 0 0 0 2
 [Output]
 5
 */
// 시간복잡도: O(2^n)
// 최악시간: 223,080
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/15686

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, m;
int board[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1)
                house.push_back({i, j});
            else if(board[i][j] == 2)
                chicken.push_back({i, j});
        }
    }
    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
    int mn = 0x7f7f7f7f;
    do {
        int dist = 0;
        for(auto h: house) {
            int tmp = 0x7f7f7f7f;
            for(int i = 0; i < chicken.size(); i++) {
                if(brute[i] == 0) continue;
                tmp = min(tmp, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y));
            }
            dist += tmp;
        }
        mn = min(mn, dist);
    } while(next_permutation(brute.begin(), brute.end()));
    cout << mn;
    
    return 0;
}
