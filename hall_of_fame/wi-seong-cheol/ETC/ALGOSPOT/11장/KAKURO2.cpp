//
//  KAKURO2.cpp
//  main
//
//  Created by wi_seong on 1/16/24.
//

/*
 [Input]
 1
 8
 0 0 0 0 0 0 0 0
 0 1 1 0 0 1 1 1
 0 1 1 0 1 1 1 1
 0 1 1 1 1 1 0 0
 0 0 1 1 0 1 1 0
 0 0 0 1 1 1 1 1
 0 1 1 1 1 0 1 1
 0 1 1 1 0 0 1 1
 24
 2 1 0 16
 2 5 0 24
 3 1 0 17
 3 4 0 29
 4 1 0 35
 5 2 0 7
 5 5 0 8
 6 3 0 16
 7 1 0 21
 7 6 0 5
 8 1 0 6
 8 6 0 3
 1 2 1 23
 1 3 1 30
 1 6 1 27
 1 7 1 12
 1 8 1 16
 2 5 1 17
 3 4 1 15
 4 7 1 12
 5 5 1 7
 5 8 1 7
 6 2 1 11
 6 3 1 10
 [Output]
 0 0 0 0 0 0 0 0
 0 9 7 0 0 8 7 9
 0 8 9 0 8 9 5 7
 0 6 8 5 9 7 0 0
 0 0 6 1 0 2 6 0
 0 0 0 4 6 1 3 2
 0 8 9 3 1 0 1 4
 0 3 1 2 0 0 2 1
 */
// 시간복잡도: O(2 ^ (n + m))
// 최악시간: 휴리스틱 최적화로 인해 측정불가
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/KAKURO2

#include <iostream>
#include <cstring>

using namespace std;
#define SIZE 55
const int INF = 987654321;
const int WHITE = 1;
const int BLACK = 0;
int t, n, q;
int color[SIZE][SIZE], value[SIZE][SIZE], hint[SIZE][SIZE][2];
int sum[SIZE * SIZE], length[SIZE * SIZE], known[SIZE * SIZE];
int candidates[10][46][1024];
int maskSum[1024], maskLen[1024];
int dx[] = {0, 1};
int dy[] = {1, 0};

int setSize(int mask) { return maskLen[mask]; }

int setSum(int mask) { return maskSum[mask]; }

void calcMasks() {
    memset(maskSum, 0, sizeof(maskSum));
    memset(maskLen, 0, sizeof(maskLen));
    for(int mask = 0; mask < 1024; mask++) {
        for(int i = 0; i < 10; i++)
            if(mask & (1 << i)) {
                maskSum[mask] += i;
                maskLen[mask]++;
            }
    }
}

void generateCandidates() {
    memset(candidates, 0, sizeof(candidates));
    for(int set = 0; set < 1024; set += 2) {
        int l = setSize(set), s = setSum(set);
        int subset = set;
        while(true) {
            candidates[l][s][subset] |= (set & ~subset);
            if(subset == 0) break;
            subset = (subset - 1) & set;
        }
    }
}

int getCandHint(int hint) {
    return candidates[length[hint]][sum[hint]][known[hint]];
}

int getCandCoord(int x, int y) {
    return getCandHint(hint[x][y][0]) & getCandHint(hint[x][y][1]);
}

void printSolution() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << (j ? " " : "") << value[i][j];
        cout << endl;
    }
}

void put(int x, int y, int val) {
    for(int h = 0; h < 2; h++)
        known[hint[x][y][h]] += (1 << val);
    value[x][y] = val;
}

void remove(int x, int y, int val) {
    for(int h = 0; h < 2; h++)
        known[hint[x][y][h]] -= (1 << val);
    value[x][y] = 0;
}

bool search() {
    int x = -1, y = -1, minCandidates = 1023;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if(color[i][j] == WHITE && value[i][j] == 0) {
                int candidates = getCandCoord(i, j);
                if(setSize(minCandidates) > setSize(candidates)) {
                    minCandidates = candidates;
                    x = i; y = j;
                }
            }
    }

    if(minCandidates == 0) return false;

    if(x == -1) {
        printSolution();
        return true;
    }

    for(int val = 1; val <= 9; ++val)
        if(minCandidates & (1 << val)) {
            put(x, y, val);
            if(search()) return true;
            remove(x, y, val);
        }

    return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    calcMasks();
    generateCandidates();

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cin >> color[i][j];
        }
        cin >> q;
        memset(hint, -1, sizeof(hint));
        for(int i = 0; i < q; i++) {
            int x, y, d;
            cin >> x >> y >> d >> sum[i];
            x--; y--;
            length[i] = 0;
            while(true) {
                x += dx[d];
                y += dy[d];
                if(x >= n || y >= n || color[x][y] == BLACK) break;
                hint[x][y][d] = i;
                length[i]++;
            }
        }
        memset(known, 0, sizeof(known));
        memset(value, 0, sizeof(value));
        search();
    }

	return 0;
}
