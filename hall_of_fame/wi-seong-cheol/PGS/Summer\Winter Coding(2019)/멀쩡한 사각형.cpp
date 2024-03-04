//
//  멀쩡한 사각형.cpp
//  main
//
//  Created by wi_seong on 2/15/24.
//

// 시간복잡도: O(logn)
// 최악시간: 9
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/62048

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll solution(int w, int h) {
    ll answer = ll(w) * ll(h);

    ll g = gcd(w, h);

    answer -= ((ll(w) / g) + (ll(h) / g) - 1) * g;

    return answer;
}
