//
//  숫자의 표현.cpp
//  main
//
//  Created by wi_seong on 1/29/24.
//

// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Level 2
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12924

#include <iostream>
#include <vector>

using namespace std;
int asum[10001];

int solution(int n) {
    int answer = 0;

    for(int i = 1; i <= n; i++)
        asum[i] = asum[i - 1] + i;

    int st = 0;
    int en = 0;
    while(st <= en) {
        while(en < n && asum[en] - asum[st] < n) {
            en++;
        }
        if(asum[en] - asum[st] == n) answer++;
        st++;
    }

    return answer;
}
