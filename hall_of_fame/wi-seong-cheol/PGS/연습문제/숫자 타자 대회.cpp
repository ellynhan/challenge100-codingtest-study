//
//  숫자 타자 대회.cpp
//  main
//
//  Created by wi_seong on 2/6/24.
//

// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/136797

#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;
int n;
int cache[13][13][100001];
unordered_map<char, pair<int, int>> m = {{'1', {0, 0}}, {'2', {0, 1}}, {'3', {0, 2}},
                                         {'4', {1, 0}}, {'5', {1, 1}}, {'6', {1, 2}},
                                         {'7', {2, 0}}, {'8', {2, 1}}, {'9', {2, 2}},
                                         {'*', {3, 0}}, {'0', {3, 1}}, {'#', {3, 2}}};
vector<pair<int, int>> input;

int getWeight(pair<int, int> pos, pair<int, int> target){
    int sx = pos.first;
    int sy = pos.second;

    int x = target.first;
    int y = target.second;

    if(sx == x && sy == y) return 1;

    if(sx == x || sy == y) return abs((sx - x) * 2 + (sy - y) * 2);

    if(abs(sx - x) == abs(sy - y)) return abs(sx - x) * 3;

    int nx = abs(sx - x);
    int ny = abs(sy - y);
    int diag = min(nx, ny);
    int line = max(nx, ny);

    return diag * 3 + (line - diag) * 2;
}

int solve(pair<int, int> left, pair<int, int> right, int k) {
    if(k >= n) return 0;
    if(left.first == right.first && left.second == right.second) return 9999999;

    int &ret = cache[left.first * 3 + left.second][right.first * 3 + right.second][k];
    if(ret != -1) return ret;

    pair<int, int> target = input[k];
    int leftValue = solve(target, right, k + 1) + getWeight(left, target);
    int rightValue = solve(left, target, k + 1) + getWeight(right, target);
    ret = min(leftValue, rightValue);

    return ret;
}

int solution(string numbers) {
    int answer = 0;
    memset(cache, -1, sizeof(cache));
    n = int(numbers.length());

    for(char number: numbers)
        input.push_back(m[number]);

    answer = solve({1, 0}, {1, 2}, 0);

    return answer;
}
