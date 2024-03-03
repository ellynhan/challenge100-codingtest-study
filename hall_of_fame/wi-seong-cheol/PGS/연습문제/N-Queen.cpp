//
//  N-Queen.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(2 ^ n)
// 최악시간: 4,096
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12952

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
int answer;
int col[12];

bool check(int level) {
    for(int i = 0; i < level; i++)
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    return true;
}

void solve(int n, int k) {
    if(k == n) {
        answer++;
        return;
    }

    for(int i = 0; i < n; i++) {
        col[k] = i;
        if(check(k)) solve(n, k + 1);
    }
}

int solution(int n) {
    solve(n, 0);

    return answer;
}
