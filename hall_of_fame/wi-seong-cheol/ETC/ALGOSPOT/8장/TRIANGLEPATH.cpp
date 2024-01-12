//
//  TRIANGLEPATH.cpp
//  main
//
//  Created by wi_seong on 1/10/24.
//

/*
 [Input]
 2
 5
 6
 1  2
 3  7  4
 9  4  1  7
 2  7  5  9  4
 5
 1
 2 4
 8 16 8
 32 64 32 64
 128 256 128 256 128
 [Output]
 28
 341
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: 하
// Timer: 10m
// Url: https://algospot.com/judge/problem/read/TRIANGLEPATH

#include <iostream>
#include <cstring>

using namespace std;
int t, n;
int triangle[101][101];
int cache[101][101];

int path(int x, int y) {
    int &ret = cache[x][y];
    if(ret != -1) return ret;
    if(x == n - 1) return triangle[x][y];
    return ret = triangle[x][y] + max(path(x + 1, y), path(x + 1, y + 1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));

        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++)
                cin >> triangle[i][j];
        }
        cout << path(0, 0) << '\n';
    }

	return 0;
}
