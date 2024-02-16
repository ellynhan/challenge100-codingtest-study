//
//  유사 칸토어 비트열.cpp
//  main
//
//  Created by wi_seong on 2/16/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 80,000,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/148652

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

bool check(ll val) {
    if (val < 5 && val != 2) return true;
    if ((val - 2) % 5 == 0) return false;
    return check(val / 5);
}

int solution(int n, long long l, long long r) {
    int answer = 0;

    for(ll i = l - 1; i < r; i++) {
        if(check(i)) answer++;
    }

    return answer;
}
