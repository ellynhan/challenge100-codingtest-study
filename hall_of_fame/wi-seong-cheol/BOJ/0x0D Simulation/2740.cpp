//
//  2740.cpp
//  main
//
//  Created by wi_seong on 3/19/24.
//

/*
 [Input]
 3 2
 1 2
 3 4
 5 6
 2 3
 -1 -2 0
 0 0 3
 [Output]
 -1 -2 6
 -3 -6 12
 -5 -10 18
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Silver 5
// Timer: 2m
// Url: https://www.acmicpc.net/problem/2740

#include <iostream>

using namespace std;
int n, m, k;
int a[101][101], b[101][101], c[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> m >> k;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            for(int l = 0; l < m; l++) {
                c[i][j] += a[i][l] * b[l][j];
            }
            cout << c[i][j] << ' ';
        }
        cout << '\n';
    }

	return 0;
}
