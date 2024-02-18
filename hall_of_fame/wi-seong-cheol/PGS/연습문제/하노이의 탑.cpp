//
//  하노이의 탑.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(2 ^ n)
// 최악시간: 32,768
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12946

#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void hanoi(int start, int target, int tmp, int n) {
    if(n == 1) {
        answer.push_back({start, target});
        return;
    }
    hanoi(start, tmp, target, n - 1);
    answer.push_back({start, target});
    hanoi(tmp, target, start, n - 1);
}

vector<vector<int>> solution(int n) {
    hanoi(1, 3, 2, n);

    return answer;
}
