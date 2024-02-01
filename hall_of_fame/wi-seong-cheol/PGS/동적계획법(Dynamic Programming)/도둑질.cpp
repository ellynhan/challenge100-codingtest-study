//
//  도둑질.cpp
//  main
//
//  Created by wi_seong on 2/1/24.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 4
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42897

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int d[2][1000001];

int solution(vector<int> money) {
    int answer = 0;
    int n = int(money.size());

    d[0][1] = money[1];
    for(int i = 2; i < n; i++) {
        d[0][i] = max(d[0][i - 1], d[0][i - 2] + money[i]);
    }

    d[1][0] = money[0];
    d[1][1] = d[1][0];
    for(int i = 2; i < n - 1; i++) {
        d[1][i] = max(d[1][i - 1], d[1][i - 2] + money[i]);
    }

    answer = max(d[0][n- 1], d[1][n - 2]);

    return answer;
}
