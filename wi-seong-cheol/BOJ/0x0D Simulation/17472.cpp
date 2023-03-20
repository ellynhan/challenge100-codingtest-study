//
//  17472.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 7 8
 0 0 0 0 0 0 1 1
 1 1 0 0 0 0 1 1
 1 1 0 0 0 0 0 0
 1 1 0 0 0 1 1 0
 0 0 0 0 0 1 1 0
 0 0 0 0 0 0 0 0
 1 1 1 1 1 1 1 1
 [Output]
 9
 */
// 시간복잡도: O(n * m)
// 최악시간: 2h
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17472

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
const int MAP_SIZE_MAX = 10;
const int ISLAND_COUNT_MAX = 6;
int n, m;
int islandCount = 1;
int minAns = -1;
int board[MAP_SIZE_MAX][MAP_SIZE_MAX];
int connect[ISLAND_COUNT_MAX][ISLAND_COUNT_MAX];
bool vis[MAP_SIZE_MAX][MAP_SIZE_MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void numbering(int x, int y, int idx) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    board[x][y] = idx;
    vis[x][y] = true;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] != -1) continue;
            board[nx][ny] = idx;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

void setConnect(int& startPoint, int& length, int tile) {
    if(startPoint == 0) {
        if(tile > 0) {
            startPoint = tile;
            length = 0;
        }
    }
    else {
        if(tile == 0) {
            length++;
        }
        else if(tile == startPoint) {
            length = 0;
        }
        else if(tile != startPoint) {
            if(length > 1) {
                if (connect[startPoint - 1][tile - 1] == 0 || length < connect[startPoint - 1][tile - 1]) {
                    connect[startPoint - 1][tile - 1] = length;
                    connect[tile - 1][startPoint - 1] = length;
                }
            }
            startPoint = tile;
            length = 0;
        }
    }
}

void setBridgeHor() {
    int startPoint = 0;
    int length = 0;
    for(int i = 0; i < n; i++) {
        startPoint = length = 0;
        for(int j = 0; j < m; j++)
            setConnect(startPoint, length, board[i][j]);
    }
}

void setBridgeVer() {
    int startPoint = 0;
    int length = 0;
    for(int j = 0; j < m; j++) {
        startPoint = length = 0;
        for(int i = 0; i < n; i++)
            setConnect(startPoint, length, board[i][j]);
    }
}

void findConnectAll(const int connectTemp[ISLAND_COUNT_MAX][ISLAND_COUNT_MAX],
                    int index, bool check[ISLAND_COUNT_MAX]) {
    check[index] = true;

    for(int i = 0; i < islandCount; i++) {
        if(i != index && connectTemp[i][index] > 0) {
            if(!check[i])
                findConnectAll(connectTemp, i, check);
        }
    }
}

bool isConnectAll(const bool check[ISLAND_COUNT_MAX]) {
    for(int i = 0; i < islandCount; i++)
        if(!check[i]) return false;
    return true;
}

void makeConnect(const int connectTemp[ISLAND_COUNT_MAX][ISLAND_COUNT_MAX],
                 int start, int end, int ans) {
    if(end == islandCount) {
        start++;
        end = start + 1;
    }
    // 종료
    if(start == islandCount - 1) {
        bool check[ISLAND_COUNT_MAX];
        for (int i = 0; i < ISLAND_COUNT_MAX; i++) {
            check[i] = false;
        }
        findConnectAll(connectTemp, 0, check);
        if(isConnectAll(check)) {
            if(minAns < 0 || minAns > ans)
                minAns = ans;
        }
        return;
    }

    int connectCopy[ISLAND_COUNT_MAX][ISLAND_COUNT_MAX];
    copy(&connectTemp[0][0], &connectTemp[0][0] + ISLAND_COUNT_MAX * ISLAND_COUNT_MAX, &connectCopy[0][0]);

    // 미건설
    makeConnect(connectCopy, start, end + 1, ans);
    // 건설
    if(connect[start][end] > 0) {
        connectCopy[start][end] = connectCopy[end][start] = 1;
        makeConnect(connectCopy, start, end + 1, ans + connect[start][end]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x; cin >> x;
            board[i][j] = -x;
        }
    }
    
    int index = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] < 0)
                numbering(i, j, index++);
                
    islandCount = index - 1;
    for(int i = 0; i < islandCount; i++)
        for(int j = 0; j < islandCount; j++)
            connect[i][j] = 0;

    setBridgeHor();
    setBridgeVer();

    int connectTemp[ISLAND_COUNT_MAX][ISLAND_COUNT_MAX] = { 0 };
    makeConnect(connectTemp, 0, 1, 0);

    cout << minAns;
    
    return 0;
}

