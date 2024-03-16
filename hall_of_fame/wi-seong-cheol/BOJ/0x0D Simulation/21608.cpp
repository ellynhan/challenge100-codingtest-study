//
//  21608.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 12/30/23.
//

/*
 [Input]
 3
 4 2 5 1 7
 3 1 9 4 5
 9 8 1 2 3
 8 1 9 3 4
 7 2 3 4 8
 1 9 2 5 7
 6 5 2 3 4
 5 1 9 2 8
 2 9 3 1 4
 [Output]
 54
 */
// 시간복잡도: O(n ^ 6)
// 최악시간: 64,000,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/21608

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
#define X first
#define Y second
struct Student {
    int idx;
    int like[4];
};
int n, ans;
int board[21][21];
vector<int> order;
int likeCnt[21][21];
int emptyCnt[21][21];
vector<Student> student;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if(a.X == b.X)
        return a.Y < b.Y;
    return a.X < b.X;
}

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    order.resize(n * n);
    student.resize(n * n + 1);
    for(int i = 0; i < n * n; i++) {
        cin >> order[i];
        for(int j = 0; j < 4; j++)
            cin >> student[order[i]].like[j];
    }

    // 번호 채우기
    for(int idx: order) {
        memset(likeCnt, 0, sizeof(likeCnt));
        memset(emptyCnt, 0, sizeof(emptyCnt));
        int likeMax = 0;    // 좋아하는 학생의 최댓값
        int emptyMax = 0;   // 빈 칸의 최댓값

        // 좋아하는 학생과 빈 칸의 갯수를 저장
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] != 0) continue;
                int like, empty;
                like = empty = 0;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(OOB(nx, ny)) continue;
                    if(board[nx][ny] == 0) {    // 빈 칸일 때
                        empty++;
                    } else {                    // 학생이 있을 때
                        for(int L: student[idx].like)
                            if(L == board[nx][ny]) {
                                like++;
                                break;
                            }
                    }
                }
                emptyCnt[i][j] = empty;
                likeCnt[i][j] = like;
                likeMax = max(likeMax, like);
            }
        }

        // 1. 좋아하는 학생이 인접한 칸에 가장 많은 칸 구하기
        vector<pair<int, int>> likeIdx;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(likeMax == likeCnt[i][j] && board[i][j] == 0)
                    likeIdx.push_back({i, j});

        if(likeIdx.size() == 1) {
            auto element = likeIdx[0];
            board[element.X][element.Y] = idx;
            continue;
        }

        // 2. 1이 여러 개 일때, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸 구하기
        vector<pair<int, int>> emptyIdx;
        for(auto element: likeIdx)
            emptyMax = max(emptyMax, emptyCnt[element.X][element.Y]);

        for(auto element: likeIdx)
            if(emptyMax == emptyCnt[element.X][element.Y])
                emptyIdx.push_back({element.X, element.Y});

        if(emptyIdx.size() == 1) {
            auto element = emptyIdx[0];
            board[element.X][element.Y] = idx;
            continue;
        }

        // 3. 2가 여러 개 일때, 행이 작은 칸 그런 칸이 많으면 열이 작은 칸
        sort(emptyIdx.begin(), emptyIdx.end(), cmp);
        auto element = emptyIdx[0];
        board[element.X][element.Y] = idx;
    }

    // 학생 만족도 계산
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(OOB(nx, ny)) continue;
                for(int idx: student[board[i][j]].like) {
                    if(idx == board[nx][ny]) {
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt == 0) continue;
            ans += pow(10, cnt - 1);
        }
    }
    cout << ans;

    return 0;
}
