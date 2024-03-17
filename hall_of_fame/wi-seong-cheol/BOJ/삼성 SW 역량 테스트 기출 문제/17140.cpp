//
//  17140.cpp
//  main
//
//  Created by wi_seong on 3/12/24.
//

/*
 [Input]
 3 3 3
 1 1 1
 1 1 1
 1 1 1
 [Output]
 2
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/17140

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int n, m;
int r, c, k;
int board[2][101][101];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void calcR(int cur) {
    int next = (cur + 1) % 2;

    for(int i = 0; i < n; i++) {
        unordered_map<int, int> cnt;
        for(int j = 0; j < m; j++) {
            cnt[board[cur][i][j]]++;
        }
        vector<pair<int, int>> v(cnt.begin(), cnt.end());
        sort(v.begin(), v.end(), cmp);

        int idx = 0;
        for(auto element: v) {
            if(element.first == 0) continue;
            board[next][i][idx++] = element.first;
            board[next][i][idx++] = element.second;
        }
        m = max(m, idx);
    }
}

void calcC(int cur) {
    int next = (cur + 1) % 2;

    for(int i = 0; i < m; i++) {
        unordered_map<int, int> cnt;
        for(int j = 0; j < n; j++) {
            cnt[board[cur][j][i]]++;
        }
        vector<pair<int, int>> v(cnt.begin(), cnt.end());
        sort(v.begin(), v.end(), cmp);

        int idx = 0;
        for(auto element: v) {
            if(element.first == 0) continue;
            board[next][idx++][i] = element.first;
            board[next][idx++][i] = element.second;
        }
        n = max(n, idx);
    }
}

void reset(int cur) {
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            board[cur][i][j] = 0;
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int cur = 0;
    n = m = 3;
    cin >> r >> c >> k;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> board[cur][i][j];
        }
    }

    int t = 0;
    while(t < 101) {
        if(board[cur][r - 1][c - 1] == k) break;
        t++;
        int next = (cur + 1) % 2;
        reset(next);
        if(n >= m) calcR(cur);
        else calcC(cur);
        cur = (cur + 1) % 2;
    }
    if(t == 101) cout << -1;
    else cout << t;

	return 0;
}
