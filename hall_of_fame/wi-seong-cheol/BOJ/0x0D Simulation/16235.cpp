//
//  16235.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 1 1 1
 1
 1 1 1
 [Output]
 1
 */
// 시간복잡도: O(n^3)
// 최악시간: 20,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/16235

#include <iostream>
#include <vector>

using namespace std;
int n, m, k;
int x, y, z;
int field[12][12];
int S2D2[12][12];
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> tree[12][12];

void run1(int x, int y) {
    auto& v = tree[x][y];
    int idx = (int)v.size() - 1;
    for(; idx >= 0; idx--) {
        if(field[x][y] < v[idx]) break;
        field[x][y] -= v[idx];
        v[idx]++;
    }
    
    for(int i = 0; i <= idx; i++)
        field[x][y] += v[i] / 2;
    
    v.erase(v.begin(), v.begin() + idx + 1);
}

void run2(int x, int y) {
    for(auto age: tree[x][y])
        if(!(age % 5))
            for(int dir = 0; dir < 8; dir++)
                tree[x + dx[dir]][y + dy[dir]].push_back(1);
    
    field[x][y] += S2D2[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            field[i][j] = 5;
            cin >> S2D2[i][j];
        }
    }
    while(m--) {
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
    while(k--) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                run1(i, j);
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                run2(i, j);
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ans += tree[i][j].size();
    cout << ans;
    
    return 0;
}
