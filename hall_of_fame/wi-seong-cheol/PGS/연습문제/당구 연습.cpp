//
//  당구 연습.cpp
//  main
//
//  Created by wi_seong on 2/16/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/169198

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int INF = 1e9 + 7;
struct Point {
    int x, y;
};

int calc(Point a, Point b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    Point start = {startX, startY};

    for(auto ball: balls) {
        int len = INF;
        if(!(start.x == ball[0] && start.y < ball[1])) {
            len = min(len, calc(start, {ball[0], n + (n - ball[1])}));
        }
        if(!(start.x < ball[0] && start.y == ball[1])) {
            len = min(len, calc(start, {m + (m - ball[0]), ball[1]}));
        }
        if(!(start.x == ball[0] && start.y > ball[1])) {
            len = min(len, calc(start, {ball[0], -ball[1]}));
        }
        if(!(start.x > ball[0] && start.y == ball[1])) {
            len = min(len, calc(start, {-ball[0], ball[1]}));
        }
        answer.push_back(len);
    }

    return answer;
}
