//
//  17837.cpp
//  main
//
//  Created by wi_seong on 3/13/24.
//

/*
 [Input]
 6 10
 0 1 2 0 1 1
 1 2 0 1 1 0
 2 1 0 1 1 0
 1 0 1 1 0 2
 2 0 1 2 0 1
 0 2 1 0 2 1
 1 1 1
 2 2 2
 3 3 4
 4 4 1
 5 5 3
 6 6 2
 1 6 3
 6 1 2
 2 4 3
 4 2 1
 [Output]
 7
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 100,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17837

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct POS {
    int x, y, d;
};
int n, k;
int posSize;
int color[13][13];
int map[13][13][5];
POS pos[10];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int turn(int idx) {
    POS& cur = pos[idx];
    int nx = cur.x + dx[cur.d];
    int ny = cur.y + dy[cur.d];
    int nd = cur.d;

    if(OOB(nx, ny) || color[nx][ny] == 2) { // OOB or 파란색
        if(cur.d % 2 == 0) nd++;
        else nd--;
        nx = cur.x + dx[nd];
        ny = cur.y + dy[nd];
        pos[idx].d = nd;
        if(OOB(nx, ny) || color[nx][ny] == 2) {
            return map[cur.x][cur.y][0];
        }
    }

    int bottom = -1;
    int& curSize = map[cur.x][cur.y][0];
    for(int i = 1; i <= curSize; i++) {
        if(map[cur.x][cur.y][i] == idx) {
            bottom = i;
            break;
        }
    }

    int move[5] = {0, };
    int& moveSize = move[0];
    for(int i = bottom; i <= curSize; i++) {
        move[++moveSize] = map[cur.x][cur.y][i];
    }
    curSize = bottom - 1;

    if(color[nx][ny] == 1) {
        for(int i = 1; i <= moveSize / 2; i++) {
            swap(move[i], move[moveSize - i + 1]);
        }
    }

    int& nextSize = map[nx][ny][0];
    for(int i = 1; i <= moveSize; i++) {
        map[nx][ny][++nextSize] = move[i];
        pos[move[i]].x = nx;
        pos[move[i]].y = ny;
        if(nextSize >= 4) return nextSize;
    }
    return nextSize;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> color[i][j];
        }
    }
    for(int i = 0; i < k; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        x--; y--; d--;
        pos[posSize] = {x, y, d};
        int& size = map[x][y][0];
        map[x][y][++size] = posSize;
        posSize++;
    }

    int ret = -1;
    for(int t = 1; t <= 1000 && ret == -1; t++) {
        for(int i = 0; i < k; i++) {
            int h = turn(i);
            if(h >= 4) {
                ret = t;
                break;
            }
        }
    }
    cout << ret;

    return 0;
}
