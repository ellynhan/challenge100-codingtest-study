//
//  미로 탈출 명령어.cpp
//  main
//
//  Created by wi_seong on 2023/02/27.
//

// 시간복잡도: O(n ^ m)
// 최악시간: 6,250,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/150365

#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char d[] = {'d', 'l', 'r', 'u'};
int check;
string tmp;

bool OOB(int x, int y, int n, int m) { return x < 1 || x > n || y < 1 || y > m; }

void dfs(int n, int m, int x, int y, int r, int c, int cnt, int k, string& answer) {
    if(check == 1) return;
    
    if(x == r && y == c && cnt == k) {
        answer = tmp;
        check = 1;
        return;
    }
    
    if(cnt + abs(x - r) + abs(y - c) > k) return;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(OOB(nx, ny, n, m)) continue;
        tmp += d[i];
        dfs(n, m, nx, ny, r, c, cnt + 1, k, answer);
        tmp.pop_back();
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    // 전체 이동 (최소)
    int mMove = abs(r - x) + abs(c - y);
    // 남은 이동 거리
    int rMove = abs(k - mMove);
    
    if(rMove % 2 == 1 || mMove > k) {
        answer = "impossible";
    } else {
        dfs(n, m, x, y, r, c, 0, k, answer);
    }
    
    return answer;
}
