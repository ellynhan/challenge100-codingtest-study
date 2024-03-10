//
//  15685.cpp
//  main
//
//  Created by wi_seong on 3/7/24.
//

/*
 [Input]
 3
 3 3 0 1
 4 2 1 3
 4 2 2 1
 [Output]
 4
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 200,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/15685

#include <iostream>

using namespace std;
int answer;
int n;
int board[101][101];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    while(n--) {
        int x, y, d, g;
        cin >> y >> x >> d >> g;

        int curve_size = 0;
        int curve[1024] = {0,};
        board[x][y] = 1;
        curve[curve_size++] = d;

        for(int i = 0; i < g; i++) {
            for(int j = curve_size - 1; j >= 0; j--) {
                curve[curve_size++] = (curve[j] + 1) % 4;
            }
        }

        for(int i = 0; i < curve_size; i++) {
            x += dx[curve[i]];
            y += dy[curve[i]];
            if(x < 0 || x > 100 || y < 0 || y > 100) continue;
            board[x][y] = 1;
        }
    }

    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            if(board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1])
                answer++;
    cout << answer;

	return 0;
}
