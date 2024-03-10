//
//  15683.cpp
//  main
//
//  Created by wi_seong on 3/7/24.
//

/*
 [Input]
 6 6
 1 0 0 0 0 0
 0 1 0 0 0 0
 0 0 1 5 0 0
 0 0 5 1 0 0
 0 0 0 0 1 0
 0 0 0 0 0 1
 [Output]
 2
 */
// 시간복잡도: O((2 ^ n) * (n * m))
// 최악시간: 4,096
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/15683

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Point {
    int x, y;
};
int answer;
int n, m;
vector<Point> cctv;
int board[8][8];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void calc(const vector<int>& d) {
    bool check[8][8] = {false, };
    int cnt = 0;

    int sz = int(cctv.size());
    vector<pair<Point, int>> v;
    for(int i = 0; i < sz; i++) {
        int val = board[cctv[i].x][cctv[i].y];
        if(val == 1) {
            v.push_back({cctv[i], d[i]});
        } else if(val == 2) {
            v.push_back({cctv[i], d[i]});
            v.push_back({cctv[i], (d[i] + 2) % 4});
        } else if(val == 3) {
            v.push_back({cctv[i], d[i]});
            v.push_back({cctv[i], (d[i] + 1) % 4});
        } else if(val == 4) {
            v.push_back({cctv[i], d[i]});
            v.push_back({cctv[i], (d[i] + 1) % 4});
            v.push_back({cctv[i], (d[i] + 2) % 4});
        } else {
            v.push_back({cctv[i], d[i]});
            v.push_back({cctv[i], (d[i] + 1) % 4});
            v.push_back({cctv[i], (d[i] + 2) % 4});
            v.push_back({cctv[i], (d[i] + 3) % 4});
        }
    }

    for(auto element: v) {
        int x = element.first.x;
        int y = element.first.y;
        int dir = element.second;
        while(true) {
            x += dx[dir];
            y += dy[dir];
            if(OOB(x, y) || board[x][y] == 6) break;
            if(check[x][y]) continue;
            check[x][y] = true;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!check[i][j] && board[i][j] == 0)
                cnt++;
        }
    }

    answer = min(answer, cnt);
}

void solve(int k, vector<int>& d) {
    if(k == 0) {
        calc(d);
        return;
    }

    for(int i = 0; i < 4; i++) {
        d.push_back(i);
        solve(k - 1, d);
        d.pop_back();
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5) {
                cctv.push_back({i, j});
            }
        }
    }

    answer = n * m;
    vector<int> d;
    solve(int(cctv.size()), d);
    cout << answer;

	return 0;
}
