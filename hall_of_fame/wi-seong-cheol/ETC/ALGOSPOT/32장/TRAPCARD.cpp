//
//  TRAPCARD.cpp
//  main
//
//  Created by wi_seong on 1/28/24.
//

/*
 [Input]
 2
 5 3
 ...
 #.#
 #.#
 #.#
 ...
 6 10
 ###.###.##
 .##.....#.
 ..#.###...
 ..###..##.
 .####..#.#
 ..........
 [Output]
 6
 ^.^
 #^#
 #.#
 #^#
 ^.^
 19
 ###.###.##
 .##^.^^^#^
 ^.#^###.^.
 .^###^.##^
 ^####.^#^#
 .^.^.^.^.^
 */
// 시간복잡도: O(V ^ 3)
// 최악시간: 8,000,000
// 난이도: 상
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/TRAPCARD

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int MXN = 200;
int H, W, n, m;
bool adj[MXN][MXN];
vector<vector<int> > id;
vector<string> board;
vector<int> aMatch, bMatch;
vector<bool> aChosen, bChosen, visited;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool inRange(const int y, const int x) {
    return 0 <= y && y < H && 0 <= x && x < W;
}

void makeGraph() {
    id = vector<vector<int>>(H, vector<int>(W, -1));

    n = m = 0;
    for(int y = 0; y < H; ++y)
        for(int x = 0; x < W; ++x)
            if(board[y][x] != '#') {
                if((y + x) % 2 == 0)
                    id[y][x] = n++;
                else
                    id[y][x] = m++;
            }
    memset(adj, false, sizeof(adj));

    for(int y1 = 0; y1 < H; ++y1)
        for(int x1 = 0; x1 < W; ++x1)
            if((y1 + x1) % 2 == 0 && board[y1][x1] != '#') {
                for(int k = 0; k < 4; ++k) {
                    int y2 = y1 + dy[k], x2 = x1 + dx[k];
                    if(inRange(y2,x2) && board[y2][x2] != '#')
                        adj[id[y1][x1]][id[y2][x2]] = true;
                }
            }
}

bool dfs(int a) {
    if(visited[a]) return false;
    visited[a] = true;
    for(int b = 0; b < m; ++b)
        if(adj[a][b])
            if(bMatch[b]==-1 || dfs(bMatch[b])) {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
    return false;
}

int bipartiteMatch() {
    aMatch = vector<int>(n, -1);
    bMatch = vector<int>(m, -1);
    int size = 0;
    for(int start = 0; start < n; start++) {
        visited = vector<bool>(n, false);
        if(dfs(start)) size++;
    }
    return size;
}

int calcMaxIndependentSet() {
    int C = bipartiteMatch();
    aChosen = vector<bool>(n, true);
    bChosen = vector<bool>(m, false);

    for(int i = 0; i < m; i++) {
        if(bMatch[i] == -1) {
            bChosen[i] = true;
        }
    }

    while(true) {
        bool changed = false;
        for(int i = 0; i < n; i++) {
            if(aChosen[i]) continue;
            for(int j = 0; j < m; j++) {
                if(bChosen[j]) continue;
                if(adj[i][j]) {
                    aChosen[i] = false;
                    bChosen[aMatch[i]] = true;
                    changed = true;
                }
            }
        }
        if(!changed) break;
    }

    return C;
}

void printUpdatedBoard() {
    for(int y = 0; y < H; y++) {
        for(int x = 0; x < W; x++) {
            if(board[y][x] == '#')
                cout << '#';
            else if(((y+x) % 2 ==0 && aChosen[id[y][x]]) ||
                    ((y+x) % 2 ==1 && bChosen[id[y][x]]))
                cout << '^';
            else
                cout << '.';
        }
        cout << '\n';
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> H >> W;
        board.clear();
        board.resize(H);
        for(int i = 0; i < H; i++) {
            cin >> board[i];
        }
        makeGraph();
        int maxSet = calcMaxIndependentSet();
        int ans = n + m - maxSet;

        cout << ans << '\n';
        printUpdatedBoard();
    }

	return 0;
}
