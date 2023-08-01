//
//  19238.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/24.
//

/*
 [Input]
 6 1 19
 1 0 0 0 1 0
 1 0 1 0 1 1
 1 0 1 0 1 0
 1 0 1 0 1 0
 1 0 1 0 1 0
 0 0 1 0 0 0
 1 3
 4 2 1 6
 [Output]
 -1
 */
// 시간복잡도: O(n * 3)
// 최악시간: 8,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/19238

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
#define pii pair<int, int>
#define X first
#define Y second
struct Person {
    int x1, y1, x2, y2;
    int distDest;   // 목적지까지의 거리는 동일하기 때문에
    bool arrive;
};
int n, m, k;
int board[21][21];
pii taxi;
vector<Person> person;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool cmp(Person& p1, Person& p2) {
    if(p1.x1 == p2.x1)
        return p1.y1 < p2.y1;
    return p1.x1 < p2.x1;
}

bool OOB(int x, int y) { return x <= 0 || x > n || y <= 0 || y > n; }

int getDist(int x1, int y1, int x2, int y2) {
    int dist[n + 1][n + 1];
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> Q;
    Q.push({x1, y1});
    dist[x1][y1] = 0;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        if(cur.X == x2 && cur.Y == y2)
            return dist[x2][y2];
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || dist[nx][ny] != -1) continue;
            if(board[nx][ny] == 1) continue;
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];
    cin >> taxi.X >> taxi.Y;
    for(int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int dist = getDist(x1, y1, x2, y2);
        person.push_back({x1, y1, x2, y2, dist, false});
    }
    sort(person.begin(), person.end(), cmp);
    
    while(1) {
        // 모든 손님을 태웠을 경우
        int cnt = 0;
        for(int i = 0; i < m; i++)
            cnt += person[i].arrive;
        if(cnt == m) {
            cout << k;
            return 0;
        }
        
        // 다음 손님을 정함
        int nxtPerson = -1;
        int dist = 0x7f7f7f7f;
        for(int i = 0; i < m; i++) {
            if(person[i].arrive) continue;
            int dist1 = getDist(taxi.X, taxi.Y, person[i].x1, person[i].y1);\
            if(dist1 == -1) continue;
            if(dist > dist1) {
                nxtPerson = i;
                dist = dist1;
            }
        }
        
        // 이동할 수 없는 경우
        if(nxtPerson == -1 || person[nxtPerson].distDest == -1) break;
        if(dist + person[nxtPerson].distDest > k) break;
        
        // 손님을 태우고 난 후
        person[nxtPerson].arrive = true;
        taxi = {person[nxtPerson].x2, person[nxtPerson].y2};
        k = k - dist + person[nxtPerson].distDest;
    }
    cout << -1;
    
    return 0;
}
