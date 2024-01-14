//
//  2174.cpp
//  main
//
//  Created by wi_seong on 1/11/24.
//

/*
 [Input]
 5 4
 2 2
 1 1 E
 5 4 W
 1 F 7
 2 F 7
 [Output]
 Robot 1 crashes into the wall
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2174

#include <iostream>
#include <unordered_map>
#include <tuple>

using namespace std;
int n, m, a, b, x, y, d, number, cnt;
int board[101][101];
char direction, op;
tuple<int, int, int> robot[101];
unordered_map<char, int> dir = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
int dx[] = {-1, 0, 1, 0}; // 북 동 남 서
int dy[] = {0, 1, 0, -1};

bool OOB(int x, int y) { return x < 1 || x > n || y < 1 || y > m; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> m >> n;
    cin >> a >> b;
    for(int i = 0; i < a; i++) {
        cin >> x >> y >> direction;
        board[n - y + 1][x] = i + 1;
        robot[i + 1] = {n - y + 1, x, dir[direction]};
    }
    while(b--) {
        cin >> number >> op >> cnt;
        while(cnt--) {
            tie(x, y, d) = robot[number];
            if(op == 'L') {
                d = (d + 3) % 4;
                robot[number] = {x, y, d};
            } else if(op == 'R') {
                d = (d + 1) % 4;
                robot[number] = {x, y, d};
            } else if(op == 'F') {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(OOB(nx, ny)) {
                    cout << "Robot " << number << " crashes into the wall";
                    return 0;
                }
                if(board[nx][ny] != 0) {
                    cout << "Robot " << number << " crashes into robot " << board[nx][ny];
                    return 0;
                }
                robot[number] = {nx, ny, d};
                board[x][y] = 0;
                board[nx][ny] = number;
            } else {
                cout << "ERROR";
            }
        }
    }
    cout << "OK";

	return 0;
}
