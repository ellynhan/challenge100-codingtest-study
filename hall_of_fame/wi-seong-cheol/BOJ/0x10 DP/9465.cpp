//
//  9465.cpp
//  main
//
//  Created by wi_seong on 2022/12/26.
//

/*
 [Input]
 2
 5
 50 10 100 20 40
 30 50 70 10 60
 7
 10 30 10 50 100 20 40
 20 40 30 50 60 20 80
 [Output]
 260
 290
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/9465

#include <iostream>
#include <algorithm>

using namespace std;
int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> n;
        int arr[2][n + 1];
        int d[2][n + 1];
        for(int i = 0; i < 2; i++) {
            fill(d[i], d[i] + n + 1, 0);
            for(int j = 1; j <= n; j++)
                cin >> arr[i][j];
        }
        d[0][1] = arr[0][1];
        d[1][1] = arr[1][1];
        for(int i = 2; i <= n; i++) {
            d[0][i] = arr[0][i] + max({d[1][i - 1], d[0][i - 2], d[1][i - 2]});
            d[1][i] = arr[1][i] + max({d[0][i - 1], d[0][i - 2], d[1][i - 2]});
        }
        cout << max(d[0][n], d[1][n]) << '\n';
    }
    
    return 0;
}
