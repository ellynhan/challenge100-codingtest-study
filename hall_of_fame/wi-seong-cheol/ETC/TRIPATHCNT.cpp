//
//  TRIPATHCNT.cpp
//  main
//
//  Created by wi_seong on 1/11/24.
//

/*
 [Input]
 2
 4
 1
 1 1
 1 1 1
 1 1 1 1
 4
 9
 5 7
 1 3 2
 3 5 5 6
 [Output]
 8
 3
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: 중
// Timer: 40m
// Url: https://www.algospot.com/judge/problem/read/TRIPATHCNT

#include <iostream>
#include <cstring>

using namespace std;
int t, n;
int triangle[101][101];
int countCache[101][101];
int pathCache[101][101];

void init() {
    memset(countCache, -1, sizeof(countCache));
    memset(pathCache, -1, sizeof(pathCache));
}

int path(int x, int y) {
    if(x == n - 1) return triangle[x][y];
    int &ret = pathCache[x][y];
    if(ret != -1) return ret;

    return ret = max(path(x + 1, y), path(x + 1, y + 1)) + triangle[x][y];
}

int count(int x, int y) {
    if(x == n - 1) return 1;

    int &ret = countCache[x][y];
    if(ret != -1) return ret;

    ret = 0;
    if(path(x + 1, y) <= path(x + 1, y + 1)) ret += count(x + 1, y + 1);
    if(path(x + 1, y) >= path(x + 1, y + 1)) ret += count(x + 1, y);

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        init();
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++)
                cin >> triangle[i][j];
        }
        cout << count(0, 0) << '\n';
    }

	return 0;
}
