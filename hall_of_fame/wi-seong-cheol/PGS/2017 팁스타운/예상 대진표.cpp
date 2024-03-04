//
//  예상 대진표.cpp
//  main
//
//  Created by wi_seong on 2/8/24.
//

// 시간복잡도: O(logn)
// 최악시간: 20
// 난이도: Level 2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12985

#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b) {
    if(a > b) swap(a, b);
    int round = 1;

    while(true) {
        if(a % 2 == 1 && a + 1 == b) {
            return round;
        }
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        round++;
    }

    return 0;
}
