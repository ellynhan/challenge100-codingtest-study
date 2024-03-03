//
//  경사로의 개수.cpp
//  main
//
//  Created by wi_seong on 2/18/24.
//

// 시간복잡도: O(n ^ 3)
// 최악시간: 640,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/214290

#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<long long>> mulMatrix(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
    int n = a.size();
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] = (result[i][j] + (a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
            }
        }
    }
    return result;
}

int solution(vector<vector<int>> grid, vector<int> d, int k) {
    int n = grid.size();
    int m = grid[0].size();
    int dl = d.size();

    vector<vector<vector<long long>>> dp(dl + 1, vector<vector<long long>>(n * m, vector<long long>(n * m, 0)));

    for (int i = 0; i < n * m; ++i) {
        dp[0][i][i] = 1;
    }

    for (int l = 1; l <= dl; ++l) {
        for (int i = 0; i < n * m; ++i) {
            int x = i % m;
            int y = i / m;
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[ny][nx] - grid[y][x] != d[l - 1]) {
                    continue;
                }
                for (int j = 0; j < n * m; ++j) {
                    dp[l][j][ny * m + nx] = (dp[l][j][ny * m + nx] + dp[l - 1][j][i]) % MOD;
                }
            }
        }
    }

    int count = 0;
    while ((1 << count) < k) {
        count++;
    }

    vector<vector<vector<long long>>> edgePower(count + 1, vector<vector<long long>>(n * m, vector<long long>(n * m, 0)));
    edgePower[0] = dp[dl];
    for (int c = 1; c <= count; ++c) {
        edgePower[c] = mulMatrix(edgePower[c - 1], edgePower[c - 1]);
    }

    vector<vector<long long>> mat(n * m, vector<long long>(n * m, 0));
    for (int i = 0; i < n * m; ++i) {
        mat[i][i] = 1;
    }

    int kNum = k;
    while (kNum > 0) {
        if (kNum >= (1 << count)) {
            mat = mulMatrix(mat, edgePower[count]);
            kNum -= (1 << count);
        }
        count--;
    }

    long long answer = 0;
    for (int i = 0; i < n * m; ++i) {
        for (int j = 0; j < n * m; ++j) {
            answer = (answer + mat[i][j]) % MOD;
        }
    }

    return answer;
}
