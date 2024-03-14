//
//  20056.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 12/29/23.
//

/*
 [Input]
 4 2 1
 1 1 5 2 2
 1 4 7 1 6
 [Output]
 8
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/20056

#include <iostream>
#include <vector>

using namespace std;
struct Fireball {
    int r, c, m, s, d;
    bool isDelete;
};
int ans;
int N, M, K, r, c, m, s, d;
vector<Fireball> fireball;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void OOB(int& x, int& y) {
    if(x < 1) x += N;
    if(x > N) x -= N;
    if(y < 1) y += N;
    if(y > N) y -= N;
}

// 모든 파이어볼 이동
void moveFireball() {
    for(auto& f: fireball) {
        if(f.isDelete) continue;
        int nx = f.r + dx[f.d] * (f.s % N);
        int ny = f.c + dy[f.d] * (f.s % N);
        OOB(nx, ny);
        f.r = nx;
        f.c = ny;
    }
}

// 파이어볼 합치기
void divideFireball(vector<int>& v) {
    int cnt = (int)v.size();
    int dir = fireball[v[0]].d % 2;
    int x = fireball[v[0]].r;
    int y = fireball[v[0]].c;
    bool flag = false;  // 홀수 짝수 판별
    int sumM, sumS;
    sumM = sumS = 0;
    for(int i = 0; i < cnt; i++) {
        int idx = v[i];
        if(fireball[idx].d % 2 != dir)
            flag = true;
        sumM += fireball[idx].m;
        sumS += fireball[idx].s;
        fireball[idx].isDelete = true;
    }

    if(sumM / 5 == 0) return;
    for(int d = 0; d <= 6; d += 2)
        fireball.push_back({x, y, sumM / 5, sumS / cnt, flag + d, false});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    while(M--) {
        cin >> r >> c >> m >> s >> d;
        fireball.push_back({r, c, m, s, d, false});
    }
    while(K--) {
        // 모든 파이어볼 이동
        moveFireball();

        vector<int> board[51][51];
        for(int i = 0; i < fireball.size(); i++) {
            auto f = fireball[i];
            if(!f.isDelete)
                board[f.r][f.c].push_back(i);
        }
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(board[i][j].size() > 1) {
                    // 파이어볼 나누기
                    divideFireball(board[i][j]);
                }
            }
        }
    }
    for(auto f: fireball)
        if(!f.isDelete)
            ans += f.m;
    cout << ans;

    return 0;
}
