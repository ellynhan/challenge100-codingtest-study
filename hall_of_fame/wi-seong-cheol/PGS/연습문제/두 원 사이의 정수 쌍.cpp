//
//  두 원 사이의 정수 쌍.cpp
//  main
//
//  Created by wi_seong on 2/15/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/181187

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll solution(int r1, int r2) {
    ll answer = 0;

    for(int i = 1; i < r2; i++) {
        if(i < r1) {
            ll mn = ceil(sqrt(pow(r1, 2) - pow(i, 2)));
            ll mx = floor(sqrt(pow(r2, 2) - pow(i, 2)));
            answer += mx - mn + 1;
        } else {
            answer += floor(sqrt(pow(r2, 2) - pow(i, 2))) + 1;
        }
    }
    answer++;
    answer *= 4;

    return answer;
}
