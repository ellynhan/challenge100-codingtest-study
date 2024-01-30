//
//  스티커 모으기(2).cpp
//  main
//
//  Created by wi_seong on 1/30/24.
//

// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12971

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int d[2][100001];

int solution(vector<int> sticker) {
    int answer = 0;
    int n = int(sticker.size());
    if(n == 1) return sticker[0];

    d[1][0] = sticker[0];
    d[1][1] = d[1][0];
    for(int i = 2; i < n; i++) {
        d[1][i] = max(sticker[i] + d[1][i - 2], d[1][i - 1]);
    }
    for(int i = 1; i <= n; i++) {
        d[0][i] = max(sticker[i] + d[0][i - 2], d[0][i - 1]);
    }
    answer = max(d[0][n - 1], d[1][n - 2]);

    return answer;
}
