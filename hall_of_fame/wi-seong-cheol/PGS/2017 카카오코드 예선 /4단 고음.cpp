//
//  4단 고음.cpp
//  main
//
//  Created by wi_seong on 2/12/24.
//

// 시간복잡도: O(3 ^ 10)
// 최악시간: 59,049
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1831#

#include <iostream>
#include <cmath>

using namespace std;
int answer;

void solve(int k, int cnt) {
    if(k < 3 || pow(3, cnt / 2) > k) return;

    if(k == 3) {
        if(cnt == 2) answer++;
        return;
    }

    if(k % 3 == 0 && cnt >= 2) solve(k / 3, cnt - 2);

    solve(k - 1, cnt + 1);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n) {
    answer = 0;

    solve(n - 2, 2);

    return answer;
}
