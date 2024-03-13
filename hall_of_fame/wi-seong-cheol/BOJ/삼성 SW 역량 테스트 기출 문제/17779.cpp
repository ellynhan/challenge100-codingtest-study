//
//  17779.cpp
//  main
//
//  Created by wi_seong on 3/13/24.
//

/*
 [Input]
 6
 1 2 3 4 1 6
 7 8 9 1 4 2
 2 3 4 1 1 3
 6 6 6 6 9 4
 9 1 9 1 9 5
 1 1 1 1 9 9
 [Output]
 18
 */
// 시간복잡도: O(n ^ 6)
// 최악시간: 4,332,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/17779

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF = 1e9 + 7;
int total;
int n;
int board[21][21];

int solve(int x, int y, int d1, int d2) {
    vector<int> v(5, 0);
    int tmp[21][21] = {0, };

    for(int i = 0; i <= d1; i++) {
        tmp[x + i][y - i] = 5;
        tmp[x + d2 + i][y + d2 - i] = 5;
    }
    for(int i = 0; i <= d2; i++) {
        tmp[x + i][y + i] = 5;
        tmp[x + d1 + i][y - d1 + i] = 5;
    }

    for(int i = 1; i < x + d1; i++) {
        for(int j = 1; j <= y; j++) {
            if(tmp[i][j] == 5) break;
            v[0] += board[i][j];
        }
    }
    for(int i = 1; i <= x + d2; i++) {
        for(int j = n; j > y; j--) {
            if(tmp[i][j] == 5) break;
            v[1] += board[i][j];
        }
    }
    for(int i = x + d1; i <= n; i++) {
        for(int j = 1; j < y - d1 + d2; j++) {
            if(tmp[i][j] == 5) break;
            v[2] += board[i][j];
        }
    }
    for(int i = x + d2 + 1; i <= n; i++) {
        for(int j = n; j >= y - d1 + d2; j--) {
            if(tmp[i][j] == 5) break;
            v[3] += board[i][j];
        }
    }
    v[4] = total - (v[0] + v[1] + v[2] + v[3]);

    sort(v.begin(), v.end());
    return v[4] - v[0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> board[i][j];
            total += board[i][j];
        }
    }

    int ans = INF;
    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= n; y++) {
            for(int d1 = 1; d1 <= n; d1++) {
                for(int d2 = 1; d2 <= n; d2++) {
                    if(x + d1 + d2 > n) continue;
                    if(y - d1 < 1) continue;
                    if(y + d2 > n) continue;
                    ans = min(ans, solve(x, y, d1, d2));
                }
            }
        }
    }
    cout << ans;

	return 0;
}
