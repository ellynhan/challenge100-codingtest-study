//
//  1080.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/06.
//

/*
 [Input]
 3 4
 0000
 0010
 0000
 1001
 1011
 1001
 [Output]
 2
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 6,250,000
// 난이도: Silver 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1080

#include <iostream>

using namespace std;
int ans;
int n, m;
char a[51][51];
char b[51][51];

bool isSame() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] != b[i][j])
                return false;
    return true;
}

void changeBlock(int x, int y) {
    for(int i = x; i < x + 3; i++)
        for(int j = y; j < y + 3; j++)
            a[i][j] = (a[i][j] == '1') ? '0' : '1';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> b[i][j];
    for(int i = 0; i <= n - 3; i++)
        for(int j = 0; j <= m - 3; j++) {
            if(a[i][j] != b[i][j]) {
                changeBlock(i, j);
                ans++;
            }
            if(isSame()) {
                cout << ans;
                return 0;
            }
        }
    if(isSame()) cout << ans;
    else cout << -1;
    
    return 0;
}
