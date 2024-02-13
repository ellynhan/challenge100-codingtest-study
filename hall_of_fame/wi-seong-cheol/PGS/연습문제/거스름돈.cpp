//
//  거스름돈.cpp
//  main
//
//  Created by wi_seong on 1/31/24.
//

// 시간복잡도: O(n * m)
// 최악시간: 10,000,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12907

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int mod = 1e9 + 7;
int d[100001];

int solution(int n, vector<int> money) {
    int answer = 0;
    int m = int(money.size());

    d[0] = 1;
    for(int cost: money) {
        for(int i = cost; i <= n; i++) {
            d[i] += d[i - cost];
        }
    }

    answer = d[n];

    return answer;
}
