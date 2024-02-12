//
//  2차원 동전 뒤집기.cpp
//  main
//
//  Created by wi_seong on 2/5/24.
//

// 시간복잡도: O(2 ^ (n + m))
// 최악시간: 1,048,576
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/131703#

#include <string>
#include <vector>
#include <bitset>

using namespace std;
int n, m;
vector<vector<int>> b, target;

bool compare(const vector<vector<int>>& beginning, const vector<vector<int>>& target, int row, int col) {
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            int diff = ((row >> r) % 2 + ((col >> c) % 2)) % 2;
            if((beginning[r][c] + diff) % 2 != target[r][c]) {
                return false;
            }
        }
    }
    return true;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    n = int(beginning.size());
    m = int(beginning[0].size());
    int answer = n * m + 1;

    for(int row = 0; row < (1 << n); ++row) {
        for (int col = 0; col < (1 << m); ++col) {
            int cnt = bitset<32>(row).count() + bitset<32>(col).count();
            if (cnt < answer && compare(beginning, target, row, col)) {
                answer = cnt;
            }
        }
    }

    if(answer == n * m + 1) return -1;
    return answer;
}
