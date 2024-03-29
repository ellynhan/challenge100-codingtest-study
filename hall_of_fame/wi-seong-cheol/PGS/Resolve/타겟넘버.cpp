//
//  타겟넘버.cpp
//  main
//
//  Created by wi_seong on 3/19/24.
//

// 시간복잡도: O(2 ^ n)
// 최악시간: 1,048,576;
// 난이도: Level 2
// Timer: 5m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;
int answer;
int n, target;
vector<int> number;

void solve(int k, int sum) {
    if(k == n) {
        if(sum == target) answer++;
        return;
    }

    solve(k + 1, sum + number[k]);
    solve(k + 1, sum - number[k]);
}

int solution(vector<int> numbers, int _target) {
    number = numbers;
    target = _target;
    n = int(numbers.size());

    solve(0, 0);

    return answer;
}
