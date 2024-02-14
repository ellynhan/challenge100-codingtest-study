//
//  테이블 해시 함수.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(n * m)
// 최악시간: 1,250,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/147354

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int k;

bool cmp(const vector<int>& a, const vector<int>& b) {
    if(a[k - 1] == b[k - 1]) return a[0] > b[0];
    return a[k - 1] < b[k - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    int n = int(data.size());
    int m = int(data[0].size());
    k = col;

    sort(data.begin(), data.end(), cmp);

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            sum += data[i][j] % (i + 1);
        }
        if(row_begin <= i + 1 && i + 1 <= row_end) {
            answer ^= sum;
        }
    }

    return answer;
}
