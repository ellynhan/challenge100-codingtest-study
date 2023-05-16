//
//  15684.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 6 5 6
 1 1
 3 2
 1 3
 2 5
 5 5
 [Output]
 3
 */
// 시간복잡도: O(n * m)
// 최악시간: 4,800
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/15684

#include <iostream>

using namespace std;
#define st first
#define en second
int n, m, h, ans, a, b;
int ladder[31][11];

// 사다리 이동 시뮬레이션
bool check() {
    for(int j = 1;j <= n; j++) {
        int col = j;
        for(int i = 1; i <= h; i++) {
            if(ladder[i][col]) col++;
            else if(ladder[i][col - 1]) col--;
        }
        
        if(col != j) return false;
    }
    
    return true;
}

// 백트랙킹으로 추가할 가로선을 고른다
void dfs(int depth, int cnt) {
    if(depth == cnt) {
        if(check()) {
            cout << depth;
            exit(0);
        }
        return;
    }
    
    for(int j = 1; j < n; j++) {
        for(int i = 1; i <= h; i++) {
            if(ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1]) continue;
            ladder[i][j] = 1;
            dfs(depth, cnt + 1);
            ladder[i][j] = 0;
            
            while(!ladder[i][j - 1] && !ladder[i][j + 1])
                i++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> h;
    ans = -1;
    while(m--) {
        cin >> a >> b;
        ladder[a][b] = 1;
    }
    for(int i = 0; i < 4; i++)
        dfs(i, 0);
    cout << ans;
    
    return 0;
}
