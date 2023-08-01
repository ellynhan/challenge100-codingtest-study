#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321
#define MAX 100

bool board[MAX][MAX] = {0};
int DP[MAX][MAX] = {0};
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = INF;
    
    characterX -= 1;
    characterX *= 2;
    characterY -= 1;
    characterY *= 2;
    itemX -= 1;
    itemX *= 2;
    itemY -= 1;
    itemY *= 2;
    
    FOR(i, MAX) {
        FOR(j, MAX) {
            DP[i][j] = INF;
        }
    }
    
    FOR(r, rectangle.size()) {
        int startX = (rectangle[r][0] - 1) * 2;
        int startY = (rectangle[r][1] - 1) * 2;
        int endX = (rectangle[r][2] - 1) * 2;
        int endY = (rectangle[r][3] - 1) * 2;
        
        // cout << startX << ' ' << startY << ' ' <<endX << ' '<< endY << '\n';
        for (int i = startX; i <= endX; i++) {
            board[i][startY] = 1;
            board[i][endY] = 1;
        }
        for (int j = startY; j <= endY; j++) {
            board[startX][j] = 1;
            board[endX][j] = 1;
        }
    }
    
    
    FOR(r, rectangle.size()) {
        int startX = (rectangle[r][0] - 1) * 2;
        int startY = (rectangle[r][1] - 1) * 2;
        int endX = (rectangle[r][2] - 1) * 2;
        int endY = (rectangle[r][3] - 1) * 2;
        for (int i = startX + 1; i < endX; i++) {
            for (int j = startY + 1; j < endY; j++) {
                board[i][j] = 0;
            }
        }
    }
    
    // FOR(a, 11) {
    //     FOR(b, 11) {
    //         cout << board[a][b] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{characterX, characterY}, 0});
    DP[characterX][characterY] = 0;
    while(!Q.empty()) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int depth = Q.front().second;
        Q.pop();
        
        if (x == itemX && y == itemY) {
            answer = min(answer, depth);
        }
        
        if (DP[x][y] < depth) continue;
        DP[x][y] = depth;
        
        FOR(i, 4) {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            if (0 <= nextX && nextX <= MAX &&
                0 <= nextY && nextY <= MAX &&
                board[nextX][nextY]) Q.push({{nextX, nextY}, depth + 1});
        }
    }
    
    return answer / 2;
}