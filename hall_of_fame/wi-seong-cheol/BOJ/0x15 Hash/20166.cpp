//
//  20166.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3 3 2
 aaa
 aba
 aaa
 aa
 bb
 [Output]
 56
 0
 */
// 시간복잡도: O(nm8^5))
// 최악시간: 4,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/20166

#include <iostream>
#include <unordered_map>

using namespace std;
int n, m, k;
string s;
string board[11];
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};
unordered_map<string, int> ans;

void dfs(int x, int y, int len, string str) {
    if(len == 5) {
        return;
    }
    ans[str]++;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0) nx = n - 1;
        if(nx >= n) nx = 0;
        if(ny < 0) ny = m - 1;
        if(ny >= m) ny = 0;

        dfs(nx, ny, len + 1, str + board[nx][ny]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input = "";
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dfs(i, j, 0, input + board[i][j]);
    while(k--) {
        cin >> s;
        cout << ans[s] << '\n';
    }
    
    return 0;
}
