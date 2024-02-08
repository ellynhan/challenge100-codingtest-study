//
//  최고의 집합.cpp
//  main
//
//  Created by wi_seong on 1/29/24.
//

// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Level 3
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12938

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(s < n) {
        vector<int> ret(1, -1);
        return ret;
    }
    vector<int> answer(n, s / n);

    for(int i = n - 1; i >= n - (s % n); i--) {
        answer[i]++;
    }

    return answer;
}
