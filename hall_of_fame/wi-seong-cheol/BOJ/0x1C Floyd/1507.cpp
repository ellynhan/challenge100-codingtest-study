//
//  1507.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 0 6 15 2 6
 6 0 9 8 12
 15 9 0 16 18
 2 8 16 0 4
 6 12 18 4 0
 [Output]
 55
 */
// 시간복잡도: O(n^3)
// 최악시간: 8,000
// 난이도: Gold 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1507

#include <iostream>

using namespace std;
int n;
int d[22][22];
bool u[22][22];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> d[i][j];
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            bool isunit = true;
            for(int k = 1; k <= n; k++) {
                if(k == i || k == j) continue;
                int tmp = d[i][k] + d[k][j];
                if(tmp < d[i][j]) {
                    cout << -1;
                    return 0;
                } else if(tmp == d[i][j]) {
                    isunit = false;
                }
            }
            if(isunit) u[i][j] = u[j][i] = true;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(u[i][j]) ans += d[i][j];
    cout << ans;
    
    return 0;
}
