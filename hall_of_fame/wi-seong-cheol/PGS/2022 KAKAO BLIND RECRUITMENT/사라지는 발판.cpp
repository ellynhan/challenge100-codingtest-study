//
//  사라지는 발판.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/01.
//

// 시간복잡도: O(2 ^ n)
// 최악시간: 33,554,432
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92345

#include <string>
#include <vector>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m;
bool vis[5][5];
vector<vector<int>> block;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

// 반환 값이 짝수 = 플레이어의 패배, 반환 값이 홀수 = 플레이어의 승리
// curx, cury = 현재 플레이어의 좌표 | opx, opy = 상대 플레이어의 좌표
int solve(int curx, int cury, int opx, int opy) {
    if(vis[curx][cury]) return 0;
    int ret = 0;
    
    for(int dir = 0; dir < 4; dir++) {
        int nx = curx + dx[dir];
        int ny = cury + dy[dir];
        if(OOB(nx, ny) || vis[nx][ny] || !block[nx][ny]) continue;
        vis[curx][cury] = 1;
        int val = solve(opx, opy, nx, ny) + 1;
        vis[curx][cury] = 0;
        
        // 현재 저장된 턴은 패배, 새로 계산된 턴은 승리
        if(ret % 2 == 0 && val % 2 == 1)
            ret = val;              // 바로 갱신
        // 현재 저장된 턴과 새로 계산된 턴 모두 패배
        else if(ret % 2 == 0 && val % 2 == 0)
            ret = max(ret, val);    // 최대한 늦게 지는 것
        // 현재 저장된 턴과 새로 계산된 턴 모두 승리
        else if(ret % 2 == 1 && val % 2 == 1)
            ret = min(ret, val);    // 최대한 빨리 이기는 것
    }
    
    return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = board.size();
    m = board[0].size();
    block = board;
    return solve(aloc[0], aloc[1], bloc[0], bloc[1]);
}
