//
//  짝수 행 세기.cpp
//  main
//
//  Created by wi_seong on 2/13/24.
//

// 시간복잡도: O(n ^ 2 * m)
// 최악시간: 27,000,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/68647

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int MOD = 1e7 + 19;
ll nCr[301][301];
ll dp[301][301];
int countOne[301];

int solution(vector<vector<int>> a) {
    int row = int(a.size());
    int col = int(a[0].size());

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            countOne[j] += a[i][j];
        }
    }

    nCr[0][0] = 1;
    for(int i = 1; i <= row; i++) {
        for(int j = 0; j <= row; j++) {
            if(j == 0) nCr[i][j] = 1;
            else if(i == j) nCr[i][j] = 1;
            else nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
            nCr[i][j] %= MOD;
        }
    }

    dp[1][row - countOne[0]] = nCr[row][row - countOne[0]];

    for(int c = 1; c < col; c++) {
        int oneCnt = countOne[c];
        for(int even_num = 0; even_num <= row; even_num++) {
            if(dp[c][even_num] == 0) continue;
            for(int k = 0; k <= oneCnt; k++) {
                if(even_num < k) continue;

                int be_even_row = even_num + oneCnt - (2 * k);
                if(be_even_row > row) continue;

                ll result = (nCr[even_num][k] * nCr[row - even_num][oneCnt - k]) % MOD;
                dp[c + 1][be_even_row] = (dp[c + 1][be_even_row] + dp[c][even_num] * result);
                dp[c + 1][be_even_row] %= MOD;
            }
        }
    }

    return dp[col][row];
}
