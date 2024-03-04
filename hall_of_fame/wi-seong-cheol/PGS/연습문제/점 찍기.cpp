//
//  점 찍기.cpp
//  main
//
//  Created by wi_seong on 2/15/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/140107

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll solution(int k, int d) {
    ll answer = 0;

    for(int i = 0; i <= d; i += k) {
        answer += floor(sqrt(pow(d, 2) - pow(i, 2)) / k) + 1;
    }
    return answer;
}
