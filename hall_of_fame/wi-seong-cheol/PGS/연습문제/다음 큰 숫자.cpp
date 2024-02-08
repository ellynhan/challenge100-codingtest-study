//
//  다음 큰 숫자.cpp
//  main
//
//  Created by wi_seong on 1/29/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12911

#include <iostream>
#include <vector>

using namespace std;

int countOne(int n) {
    int ret = 0;
    for(int i = 0; i < 32; i++) {
        if(n & 0x01 << i) ret++;
    }
    return ret;
}

int solution(int n) {
    int k = countOne(n);

    while(true) {
        n++;
        if(countOne(n) == k) return n;
    }

    return 0;
}
