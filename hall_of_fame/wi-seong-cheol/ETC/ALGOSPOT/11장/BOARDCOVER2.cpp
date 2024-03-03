//
//  BOARDCOVER2.cpp
//  main
//
//  Created by wi_seong on 1/16/24.
//

/*
 [Input]
 2
 4 7 2 3
 ##.##..
 #......
 #....##
 #..####
 ###
 #..
 5 10 3 3
 ..........
 ..........
 ..........
 ..........
 ..........
 .#.
 ###
 ..#
 [Output]
 3
 8
 */
// 시간복잡도: O(4 ^ (n + m)
// 최악시간: 휴리스틱 최적화로 인해 측정불가
// 난이도: 하
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/BOARDCOVER2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n, m, r, c;
int blockSize;
int covered[10][10];
int best;
vector<string> board, cover;
vector<vector<pair<int, int>>> rotations;

vector<string> rotate(const vector<string>& arr) {
    vector<string> ret(arr[0].size(), string(arr.size(), ' '));
    for(int i = 0; i < arr.size(); i++)
        for(int j = 0; j < arr[0].size(); j++)
            ret[j][arr.size() - i - 1] = arr[i][j];
    return ret;
}

void generateRotaions(vector<string> block) {
    rotations.clear();
    rotations.resize(4);
    for(int rot = 0; rot < 4; rot++) {
        int originY = -1, originX = -1;
        for(int i = 0; i < block.size(); i++)
            for(int j = 0; j < block[0].size(); j++)
                if(block[i][j] == '#') {
                    if(originY == -1) {
                        originY = i;
                        originX = j;
                    }
                    rotations[rot].push_back(make_pair(i - originY, j - originX));
                }
        block = rotate(block);
    }
    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());

    blockSize = int(rotations[0].size());
}

bool set(int y, int x, const vector<pair<int, int>>& block, int delta) {
    bool ok = true;
    for(int i = 0; i < block.size(); i++) {
        int cy = y + block[i].first, cx = x + block[i].second;
        if(cy < 0 || cx < 0 || cy >= n || cx >= m)
            ok = false;
        else {
            covered[cy][cx] += delta;
            if(covered[cy][cx] > 1) ok = false;
        }
    }
    return ok;
}

void search(int placed, int blanks) {
    int y = -1, x = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            if(covered[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        if(y != -1) break;
    }
    if(y == -1) {
        best = max(best, placed);
        return;
    }
    
    int upperBound = blanks / blockSize + placed;
    if(upperBound <= best) return;

    for(int i = 0; i < rotations.size(); i++) {
        if(set(y, x, rotations[i], 1))
            search(placed + 1, blanks - blockSize);
        set(y, x, rotations[i], -1);
    }
    covered[y][x] = 1;
    search(placed, blanks - 1);
    covered[y][x] = 0;
}

int solve() {
    int blanks = 0;
    best = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            covered[i][j] = (board[i][j] == '#');
            blanks += (board[i][j] == '.');
        }
    search(0, blanks);
    return best;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m >> r >> c;
        board.resize(n);
        for(int i = 0; i < n; i++)
            cin >> board[i];
        cover.resize(r);
        for(int i = 0; i < r; i++)
            cin >> cover[i];
        generateRotaions(cover);

        cout << solve() << '\n';
    }

	return 0;
}
