//
//  11660.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 4 3
 1 2 3 4
 2 3 4 5
 3 4 5 6
 4 5 6 7
 2 2 3 4
 3 4 3 4
 1 1 4 4
 [Output]
 27
 6
 64
 */
// 시간복잡도: O(n^2)
// 최악시간: 1,048,576
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/11660

#include <iostream>

using namespace std;
int n, m, x1, x2, y1, y2;
int a[1025][1025];
int d[1025][1025];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            d[i][j] = a[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
        }
    }
    while(m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1] << '\n';
    }
    
    return 0;
}
