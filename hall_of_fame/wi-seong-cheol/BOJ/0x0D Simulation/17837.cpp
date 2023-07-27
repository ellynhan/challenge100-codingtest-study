//
//  17837.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 4 4
 0 0 2 0
 0 0 1 0
 0 0 1 2
 0 2 0 0
 2 1 1
 3 2 3
 2 2 1
 4 1 2
 [Output]
 -1
 */
// 시간복잡도: O(1000 * n * m)
// 최악시간: 120,000
// 난이도: Gold 2
// Timer: 2h
// Url: https://www.acmicpc.net/problem/17837

#include <iostream>
#include <vector>
 
using namespace std;
#define MAX 12
#define CHESS_MAX 10
struct CHESS {
    int X, Y, Dir;
};
int n, k, ans;
int x, y, d;
int MAP[MAX][MAX];
vector<int> MAP_State[MAX][MAX];
CHESS Chess[CHESS_MAX];
 
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };
 
int findDeleteIndex(int x, int y, int idx) {
    /* 해당 말을 옮긴 후, 기존 좌표에서 몇 번 삭제를 해야 하는지 찾는 함수. */
    int Cnt = 0;
    for(int i = (int)MAP_State[x][y].size() - 1; i >= 0; i--) {
        if(MAP_State[x][y][i] == idx) break;
        Cnt++;
    }
    return Cnt + 1;
}
 
int Reverse_Dir(int idx) {
    int dir = Chess[idx].Dir;
    if(dir == 1) return 2;
    else if(dir == 2) return 1;
    else if(dir == 3) return 4;
    else return 3;
}
 
void turn(int x, int y, int nx, int ny, int idx, int pos, int color) {
    if(color == 0) {
        for(int i = pos; i < MAP_State[x][y].size(); i++) {
            MAP_State[nx][ny].push_back(MAP_State[x][y][i]);
            int Idx = MAP_State[x][y][i];
            Chess[Idx].X = nx;
            Chess[Idx].Y = ny;
        }
        int deleteIndex = findDeleteIndex(x, y, idx);
        for(int i = 0; i < deleteIndex; i++) MAP_State[x][y].pop_back();
    } else if(color == 1) {
        for(int i = (int)MAP_State[x][y].size() - 1; i >= pos; i--) {
            MAP_State[nx][ny].push_back(MAP_State[x][y][i]);
            int idx = MAP_State[x][y][i];
            Chess[idx].X = nx;
            Chess[idx].Y = ny;
        }
        int deleteIndex = findDeleteIndex(x, y, idx);
        for(int i = 0; i < deleteIndex; i++) MAP_State[x][y].pop_back();
    } else {
        int dir = Reverse_Dir(idx);
        Chess[idx].Dir = dir;
        int nnx = x + dx[dir];
        int nny = y + dy[dir];
        
        if(nnx >= 0 && nny >= 0 && nnx < n && nny < n) {
            if(MAP[nnx][nny] != 2) turn(x, y, nnx, nny, idx, pos, MAP[nnx][nny]);
        }
    }
}
 
int findPosition(int x, int y, int idx) {
    /* 해당 말이 몇 번째에 위치하고 있는지 찾아서 return 하는 함수. */
    for(int i = 0; i < MAP_State[x][y].size(); i++)
        if(MAP_State[x][y][i] == idx) return i;
    return -1;
}
 
bool checkState() {
    for(int i = 0; i < k; i++) {
        int x = Chess[i].X;
        int y = Chess[i].Y;
        if(MAP_State[x][y].size() >= 4) return true;
    }
    return false;
}
 
void Solution() {
    bool flag = false;
    int time = 0;
    
    while(true) {
        if(time > 1000) break;
 
        for(int i = 0; i < k; i++) {
            int x = Chess[i].X;
            int y = Chess[i].Y;
            int dir = Chess[i].Dir;
 
            int nx = x + dx[dir];
            int ny = y + dy[dir];
 
            int pos = findPosition(x, y, i);
            if(nx >= 0 && ny >= 0 && nx < n && ny < n)
                turn(x, y, nx, ny, i, pos, MAP[nx][ny]);
            else
                turn(x, y, nx, ny, i, pos, 2);
 
            if(checkState() == true) {
                flag = true;
                break;
            }
        }
        if(flag == true) break;
        time++;
    }
 
    if(flag == true) cout << time + 1 << endl;
    else cout << -1 << endl;
}
 
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> MAP[i][j];
    for (int i = 0; i < k; i++) {
        cin >> x >> y >> d;
        Chess[i] = { --x, --y, d };
        MAP_State[x][y].push_back(i);
    }
    Solution();
 
    return 0;
}
