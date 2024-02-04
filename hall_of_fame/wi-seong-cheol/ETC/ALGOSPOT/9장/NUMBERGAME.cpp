//
//  NUMBERGAME.cpp
//  main
//
//  Created by wi_seong on 1/21/24.
//

/*
 [Input]
 3
 5
 -1000 -1000 -3 -1000 -1000
 6
 100 -1000 -1000 100 -1000 -1000
 10
 7 -5 8 5 1 -4 -8 6 7 9
 [Output]
 -1000
 1100
 7
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 2,500
// 난이도: 하
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/NUMBERGAME

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int EMPTY = -987654321;
int t, n;
int cache[50][50];
vector<int> board;

void init() {
    board.resize(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cache[i][j] = EMPTY;
}

int solve(int left, int right) {
    if(left > right) return 0;
    int &ret = cache[left][right];
    if(ret != EMPTY) return ret;

    ret = max(board[left] - solve(left + 1, right), board[right] - solve(left, right - 1));
    if(right - left + 1 >= 2) {
        ret = max(ret, -solve(left + 2, right));
        ret = max(ret, -solve(left, right - 2));
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        init();
        for(int i = 0; i < n; i++)
            cin >> board[i];
        cout << solve(0, n - 1) << endl;
    }

	return 0;
}
