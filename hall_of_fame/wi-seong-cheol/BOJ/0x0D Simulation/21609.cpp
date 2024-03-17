//
//  21609.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 12/30/23.
//

/*
 [Input]
 5 3
 2 2 -1 3 1
 3 3 2 0 -1
 0 0 0 1 2
 -1 3 1 3 2
 0 3 2 2 1
 [Output]
 77
 */
// 시간복잡도: O(n ^ 6)
// 최악시간: 64,000,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/21609

#include <iostream>
#include <deque>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define X first
#define Y second
struct Block {
    int type, x, y;
};
struct Group {
    int rainbow;
    pair<int, int> point;
    vector<Block> blocks;
};
int ans;
int n, m;
bool vis[21][21];
vector<Group> group;
deque<deque<int>> board;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void Print() {
    cout << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == -2)
                cout << ' ';
            else if(board[i][j] == -1)
                cout << '.';
            else
                cout << board[i][j];
            cout << ' ';
        }
        cout << '\n';
    }
}

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

bool cmp(Group& a, Group& b) {
    if(a.blocks.size() == b.blocks.size()) {
        if(a.rainbow == b.rainbow) {
            if(a.point.X == b.point.X) {
                return a.point.Y > b.point.Y;
            }
            return a.point.X > b.point.X;
        }
        return a.rainbow > b.rainbow;
    }
    return a.blocks.size() > b.blocks.size();
}

bool pointCmp(Block& a, Block& b) {
    if(a.type == b.type) {
        if(a.x == b.x)
            return a.y < b.y;
        return a.x < b.x;
    }
    return a.type < b.type;
}

// 밑으로 중력 작용
void gravity() {
    for(int i = 0; i < n; i++) {
        int bottom;
        if(board[n - 1][i] == -2)
            bottom = n - 1;
        else
            bottom = n - 2;
        for(int j = n - 2; j >= 0; j--) {
            if(board[j][i] == -1) {
                bottom = j - 1;
            } else if(board[j][i] >= 0) {
                if(board[bottom][i] == -2) {
                    swap(board[j][i], board[bottom][i]);
                    bottom--;
                } else {
                    bottom = j - 1;
                }
            }
        }
    }
}

// 90도 반시계 방향으로 회전
void rotate() {
    int tmp[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            tmp[n - 1 - j][i] = board[i][j];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = tmp[i][j];
}

// 블록 제거
void eraseGroup(Group& G) {
    for(auto block: G.blocks)
        board[block.x][block.y] = -2;
}

// 블록 그룹 만들기
void createGroup(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    Group G;
    G.rainbow = 0;
    int color = board[x][y];
    G.blocks.push_back({0, x, y});

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] <= -1) continue;
            if(board[nx][ny] == 0) {
                G.rainbow++;
                G.blocks.push_back({1, nx, ny});
                vis[nx][ny] = true;
                Q.push({nx, ny});
            } else {
                if(color != board[nx][ny]) continue;
                G.blocks.push_back({0, nx, ny});
                vis[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }

    if(G.blocks.size() >= 2) {
        sort(G.blocks.begin(), G.blocks.end(), pointCmp);
        G.point = {G.blocks[0].x, G.blocks[0].y};
        group.push_back(G);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == 0)
                vis[i][j] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    board.resize(n);
    for(int i = 0; i < n; i++) {
        board[i].resize(n);
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    while(1) {
        memset(vis, false, sizeof(vis));
        group.clear();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(vis[i][j] || board[i][j] <= 0) continue;
                createGroup(i, j);
            }

        if(group.size() == 0) break;

        sort(group.begin(), group.end(), cmp);
        int x = (int)group[0].blocks.size();
        ans += x * x;
        eraseGroup(group[0]);
        gravity();
        rotate();
        gravity();
    }

    cout << ans;

    return 0;
}
