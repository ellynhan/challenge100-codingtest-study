//
//  9202.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 ICPC
 ACM
 CONTEST
 GCPC
 PROGRAMM

 3
 ACMA
 APCA
 TOGI
 NEST

 PCMM
 RXAI
 ORCN
 GPCG

 ICPC
 GCPC
 ICPC
 GCPC
 [Output]
 8 CONTEST 4
 14 PROGRAMM 4
 2 GCPC 2
 */
// 시간복잡도: O(2 ^ L)
// 최악시간: 1,073,741,824
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/9202

#include <iostream>
#include <set>

using namespace std;
const int ROOT = 1;
const int MX = 300'000 * 8 + 1;
int t;
string s;
int unused = ROOT + 1;
int nxt[MX][26];
bool vis[4][4];
char board[5][5];
int point = 0, wordnum = 0; // 점수, 단어의 수
string mxlen = "";          // 최대 길이의 단어
int chk[MX];
// 0일 경우 해당 칸이 단어의 끝이 아님을 의미, 0이 아닌 다른 값일 경우 해당 칸이 단어의 끝임을 의미
// 각 boggle판마다 방문한 chk[...]에 서로 다른 값(=mark)을 넣어줄 예정

int mark = 2;
// 각 boggle판마다 방문한 표시, find 함수에서 사용됨. 각 boggle판마다 값이 달라야하기 때문에 1씩 계속 증가됨

int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int ctoi(char c) {
    return c - 'A';
}

void insert(string& s) {
    int cur = ROOT;
    for(char c: s) {
        if(nxt[cur][ctoi(c)] == -1)
            nxt[cur][ctoi(c)] = unused++;
        cur = nxt[cur][ctoi(c)];
    }
    chk[cur] = true;
}

bool OOB(int x, int y) { return x < 0 || x >= 4 || y < 0 || y >= 4; }

// trie의 find 함수와 마찬가지로 보드에서 8개의 방향에 따라 진행하며 노드를 옮겨다니면 됨
// (curx, cury)는 보드에서의 현재 위치, cur는 트라이에서의 현재 정점 번호, s는 현재까지 완성한 문자열
void find(int curx, int cury, int cur, string s){
    if(cur == -1) return;   // 트라이에서 없는 칸으로 진입했을 경우
    
    // s에 적힌 단어를 보고 적절하게 처리를 해줌
    // 정점 번호 cur에서 끝나는 단어가 있으면서 이번 boggle판에서 아직 방문을 안했다면
    if(chk[cur] != 0 && chk[cur] != mark) {
        chk[cur] = mark;
        point += score[s.size()];
        wordnum++;
        if(s.size() > mxlen.size()) mxlen = s;
        else if(s.size() == mxlen.size() && s < mxlen) mxlen = s;
    }
    
    for(int dir = 0; dir < 8; dir++) {
        // 다음에 (nx, ny)를 방문할 예정
        int nx = curx + dx[dir];
        int ny = cury + dy[dir];
        
        if(OOB(nx, ny) || vis[nx][ny]) continue;
        
        char c = board[nx][ny];
        vis[nx][ny] = true;
        find(nx, ny, nxt[cur][ctoi(c)], s + c);
        vis[nx][ny] = false;
    }
}

void solve() {
    point = 0;
    wordnum = 0;
    mxlen = "";
    for(int x = 0; x < 4; x++)
        for(int y = 0; y < 4; y++) {
            vis[x][y] = true;
            find(x, y, nxt[ROOT][ctoi(board[x][y])], string(1, board[x][y]));
            vis[x][y] = false;
        }
    cout << point << ' ' << mxlen << ' ' << wordnum << '\n';
    mark++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 26, -1);
    cin >> t;
    while(t--) {
        cin >> s;
        insert(s);
    }
    cin >> t;
    while(t--) {
        for(int i = 0; i < 4; i++)
            cin >> board[i];
        solve();
    }
    
    return 0;
}
