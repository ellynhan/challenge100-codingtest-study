//
//  17143.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 4 5 4
 4 1 3 3 8
 1 3 5 2 9
 2 4 8 4 1
 4 5 0 1 4
 [Output]
 22
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17143

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Shark {
    int x, y, speed, dir, w, idx;
};
int ans;
int R, C, M;
int r, c, s, d, z;
vector<Shark> shark;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool cmp(Shark& a, Shark& b) {
    if(a.y == b.y) {
        if(a.x == b.x)
            return a.w > b.w;
        return a.x < b.x;
    }
    return a.y < b.y;
}

bool OOB(int x, int y) { return x < 1 || x > R || y < 1 || y > C; }

void removeDuplicate() {
    sort(shark.begin(), shark.end(), cmp);
    for(int i = 0; i < shark.size() - 1; i++) {
        if(shark[i].x == shark[i + 1].x && shark[i].y == shark[i + 1].y) {
            if(shark[i].w >= shark[i + 1].w) {
                shark.erase(shark.begin() + i + 1);
            } else {
                shark.erase(shark.begin() + i);
            }
            i--;
        }
    }
}

void move() {
    for(int i = 0; i < shark.size(); i++) {
        int m = shark[i].speed;
        while(m) {
            int nx = shark[i].x + m * dx[shark[i].dir - 1];
            int ny = shark[i].y + m * dy[shark[i].dir - 1];
            
            if(OOB(nx, ny)) {
                if(shark[i].dir == 1) {
                    m -= shark[i].x - 1;
                    shark[i].x = 1;
                    shark[i].dir = 2;
                } else if(shark[i].dir == 2) {
                    m -= R - shark[i].x;
                    shark[i].x = R;
                    shark[i].dir = 1;
                } else if(shark[i].dir == 3) {
                    m -= C - shark[i].y;
                    shark[i].y = C;
                    shark[i].dir = 4;
                } else {
                    m -= shark[i].y - 1;
                    shark[i].y = 1;
                    shark[i].dir = 3;
                }
            } else {
                m = 0;
                shark[i].x = nx;
                shark[i].y = ny;
            }
        }
    }
}

int hook(int c) {
    sort(shark.begin(), shark.end(), cmp);
    for(int i = 0; i < shark.size(); i++) {
        if(shark[i].y == c) {
            int w = shark[i].w;
            shark.erase(shark.begin() + i);
            return w;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> M;
    int idx = 1;
    while(M--) {
        cin >> r >> c >> s >> d >> z;
        shark.push_back({r, c, s, d, z, idx++});
    }
    
    for(int i = 1; i <= C; i++) {
        ans += hook(i);
        if(shark.empty()) break;
        move();
        removeDuplicate();
    }
    cout << ans;
    
    return 0;
}
