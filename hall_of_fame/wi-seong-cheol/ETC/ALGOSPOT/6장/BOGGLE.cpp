//
//  BOGGLE.cpp
//  main
//
//  Created by wi_seong on 1/3/24.
//

/*
 [Input]
 1
 URLPM
 XPRET
 GIAET
 XTNZY
 XOQRS
 6
 PRETTY
 GIRL
 REPEAT
 KARA
 PANDORA
 GIAZAPX
 [Output]
 PRETTY YES
 GIRL YES
 REPEAT YES
 KARA NO
 PANDORA NO
 GIAZAPX YES
 */
// 시간복잡도: O(8 ^ 5 * n)
// 최악시간: 327,680
// 난이도: 중
// Timer: 1h
// Url: https://www.algospot.com/judge/problem/read/BOGGLE

#include <iostream>
#include <cstring>

using namespace std;
int t, n, len;
string board[5];
bool cache[10][5][5];
string str;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void init() {
    memset(cache, true, sizeof(cache));
}

bool OOB(int x, int y) { return x < 0 || x >= 5 || y < 0 || y >= 5; }

bool search(int x, int y, int idx) {
    if(idx + 1 >= len) return true;

    for(int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(OOB(nx, ny)) continue;
        if(board[nx][ny] != str[idx + 1]) continue;
        if(!cache[idx + 1][nx][ny]) continue;
        if(search(nx, ny, idx + 1))
            return true;
    }

    return cache[idx][x][y] = false;
}

string solve() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(board[i][j] == str[0] && search(i, j, 0))
                return "YES";
        }
    }
    return "NO";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        for(int i = 0; i < 5; i++)
            cin >> board[i];
        cin >> n;
        for(int i = 0; i < n; i++) {
            init();
            cin >> str;
            len = int(str.length());
            string result = solve();
            cout << str << ' ' << result << '\n';
        }
    }

	return 0;
}
