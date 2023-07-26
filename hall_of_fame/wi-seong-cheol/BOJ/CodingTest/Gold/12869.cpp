//
//  12869.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 3
 12 10 4
 [Output]
 2
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 216,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/12869

#include <iostream>
#include <cstring>

using namespace std;
const int INF = 0x7f7f7f7f;
int n;
int a[3];
int d[61][61][61];

int dfs(int a, int b, int c) {
    if(a < 0) return dfs(0, b, c);
    if(b < 0) return dfs(a, 0, c);
    if(c < 0) return dfs(a, b, 0);
    
    if(d[a][b][c] != -1) return d[a][b][c];
    if(a == 0 && b == 0 && c == 0) return 0;
    
    d[a][b][c] = INF;
    d[a][b][c] = min(d[a][b][c], dfs(a - 9, b - 3, c - 1) + 1);
    d[a][b][c] = min(d[a][b][c], dfs(a - 9, b - 1, c - 3) + 1);
    d[a][b][c] = min(d[a][b][c], dfs(a - 3, b - 9, c - 1) + 1);
    d[a][b][c] = min(d[a][b][c], dfs(a - 3, b - 1, c - 9) + 1);
    d[a][b][c] = min(d[a][b][c], dfs(a - 1, b - 9, c - 3) + 1);
    d[a][b][c] = min(d[a][b][c], dfs(a - 1, b - 3, c - 9) + 1);
    
    return d[a][b][c];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    memset(d, -1, sizeof(d));
    cout << dfs(a[0], a[1], a[2]);
    
    return 0;
}
