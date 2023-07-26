//
//  16236.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 6
 1 1 1 1 1 1
 2 2 6 2 2 3
 2 2 5 2 2 3
 2 2 2 4 6 3
 0 0 0 0 0 6
 0 0 0 0 0 9
 [Output]
 39
 */
// 시간복잡도: O((n * m) ^ 2)
// 최악시간: 160000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/16236

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int INF = 0x7f7f7f7f;
int result, n, eat;
int shark_size = 2;
pair<int, int> st;
int board[21][21];
int check[21][21];
vector<pair<int, int>> fish;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void init() {
    fish.clear();
    for(int i = 0; i < n; i++)
        fill(check[i], check[i] + n, -1);
}

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void bfs() {
    queue<pair<int, int>> Q;
    Q.push({st.X, st.Y});
    board[st.X][st.Y] = 0;
    check[st.X][st.Y] = 0;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || check[nx][ny] != -1) continue;
            if(shark_size < board[nx][ny]) continue;
            if(shark_size == board[nx][ny] || board[nx][ny] == 0) {
                check[nx][ny] = check[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            } else if(board[nx][ny] < shark_size && 0 < board[nx][ny]) {
                check[nx][ny] = check[cur.X][cur.Y] + 1;
                fish.push_back({nx, ny});
                Q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    queue<pair<int, int>> Q;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9)
                st = {i , j};
        }
    while(1) {
        init();
        if(eat >= shark_size) {
            eat -= shark_size;
            shark_size++;
        }
        bfs();
        if(fish.size() == 0) {          // 먹을 수 있는 물고기가 없을 때
            cout << result << "\n";
            return 0;
        } else if(fish.size() == 1) {   // 먹을 수 있는 물고기가 1마리 일 때
            st = fish.front();
            board[st.X][st.Y] = 0;
            eat++;
            result += check[st.X][st.Y];
        } else {                        // 먹을 수 있는 물고기가 여러 마리 일 때
            int mindist = INF;
            for(auto& f : fish) {
                mindist = min(mindist, check[f.X][f.Y]);
            }
            vector<pair<int, int>> minfish;
            for(auto& f : fish) {
                if (mindist == check[f.X][f.Y]) {
                    minfish.push_back({f.X, f.Y});
                }
            }
            if(minfish.size() != 1)
                sort(minfish.begin(), minfish.end());
            st = minfish.front();
            result += check[st.X][st.Y];
            board[st.X][st.Y] = 0;
            eat++;
        }
    }

    return 0;
}
