//
//  17143.cpp
//  main
//
//  Created by wi_seong on 3/12/24.
//

/*
 [Input]
 4 6 8
 4 1 3 3 8
 1 3 5 2 9
 2 4 8 4 1
 4 5 0 1 4
 3 3 1 2 7
 1 5 8 4 3
 3 6 2 1 2
 2 2 2 3 5
 [Output]
 22
 */
// 시간복잡도: O(n ^ 4)
// 최악시간: 100,000,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17143

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Shark {
    int s, d, z;
};
int r, c, m;
Shark map[2][101][101];

int fishing(int cur, int pos) {
    int size = 0;
    for(int y = 0; y < r; y++) {
        if(map[cur][y][pos].z != 0) {
            size = map[cur][y][pos].z;
            map[cur][y][pos].s = 0;
            map[cur][y][pos].d = 0;
            map[cur][y][pos].z = 0;
            break;
        }
    }
    return size;
}

void move(int cur) {
    int next = (cur + 1) % 2;
    for(int y = 0; y < r; y++) {
        for(int x = 0; x < c; x++) {
            map[next][y][x].s = 0;
            map[next][y][x].d = 0;
            map[next][y][x].z = 0;
        }
    }

    for(int y = 0; y < r; y++) {
        for(int x = 0; x < c; x++) {
            if(map[cur][y][x].z != 0) {
                int s = map[cur][y][x].s;
                int d = map[cur][y][x].d;
                int z = map[cur][y][x].z;
                if(d == 1) {
                    int ny = ((r - 1) * 2 - y) + s;
                    ny = ny % ((r - 1) * 2);
                    int nd = 2;
                    if(ny >= r - 1) {
                        ny = ((r - 1) * 2) - ny;
                        nd = 1;
                    }
                    if(map[next][ny][x].z < z) {
                        map[next][ny][x].s = s;
                        map[next][ny][x].d = nd;
                        map[next][ny][x].z = z;
                    }
                } else if(d == 2) {
                    int ny = y + s;
                    ny = ny % ((r - 1) * 2);
                    int nd = 2;
                    if(ny >= r - 1) {
                        ny = ((r - 1) * 2) - ny;
                        nd = 1;
                    }
                    if(map[next][ny][x].z < z) {
                        map[next][ny][x].s = s;
                        map[next][ny][x].d = nd;
                        map[next][ny][x].z = z;
                    }
                } else if(d == 3) {
                    int nx = x + s;
                    nx = nx % ((c - 1) * 2);
                    int nd = 3;
                    if(nx >= c - 1) {
                        nx = ((c - 1) * 2) - nx;
                        nd = 4;
                    }
                    if(map[next][y][nx].z < z) {
                        map[next][y][nx].s = s;
                        map[next][y][nx].d = nd;
                        map[next][y][nx].z = z;
                    }
                } else {
                    int nx = ((c - 1) * 2 - x) + s;
                    nx = nx % ((c - 1) * 2);
                    int nd = 3;
                    if(nx >= c - 1) {
                        nx = ((c - 1) * 2) - nx;
                        nd = 4;
                    }
                    if(map[next][y][nx].z < z) {
                        map[next][y][nx].s = s;
                        map[next][y][nx].d = nd;
                        map[next][y][nx].z = z;
                    }
                }
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int cur = 0;
    cin >> r >> c >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cin >> map[cur][x][y].s >> map[cur][x][y].d >> map[cur][x][y].z;
    }

    int ans = 0;
    for(int pos = 0; pos < c; pos++) {
        ans += fishing(cur, pos);
        move(cur);
        cur = (cur + 1) % 2;
    }
    cout << ans;

	return 0;
}
