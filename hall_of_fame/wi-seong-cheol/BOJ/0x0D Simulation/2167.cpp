//
//  2167.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 2 3
 1 2 4
 8 16 32
 3
 1 1 2 3
 1 2 1 2
 1 3 2 3
 [Output]
 63
 2
 36
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 90,000
// 난이도: Silver 5
// Timer: 7m
// Url: https://www.acmicpc.net/problem/2167

#include <iostream>

using namespace std;
int n, m;
int arr[301][301];
int psum[301][301];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + arr[i][j];
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int a, b, i, j;
        cin >> a >> b >> i >> j;
        a--; b--;
        cout << psum[i][j] - psum[i][b] - psum[a][j] + psum[a][b] << '\n';
    }

	return 0;
}
