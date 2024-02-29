//
//  카운트 다운.cpp
//  main
//
//  Created by wi_seong on 2/5/24.
//

// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/131129

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;
const int INF = 1e9;
int cacheCount[100001];
int cacheBonus[100001];

pair<int, int> solve(int k) {
    if(k == 0) return {0, 0};
    int &count = cacheCount[k];
    int &bonus = cacheBonus[k];
    if(count != -1) return {count, bonus};

    count = INF;
    bonus = 0;

    for(int i = 1; i <= 20; i++) {
        // 더블
        if(2 * i <= k) {
            auto result = solve(k - (2 * i));
            if(result.first + 1 < count) {
                count = result.first + 1;
                bonus = result.second;
            } else if(result.first + 1 == count) {
                if(result.second >= bonus) {
                    count = result.first + 1;
                    bonus = result.second;
                }
            }
        }
        // 트리플
        if(3 * i <= k) {
            auto result = solve(k - (3 * i));
            if(result.first + 1 < count) {
                count = result.first + 1;
                bonus = result.second;
            } else if(result.first + 1 == count) {
                if(result.second >= bonus) {
                    count = result.first + 1;
                    bonus = result.second;
                }
            }
        }
        // 싱글
        if(i <= k) {
            auto result = solve(k - i);
            if(result.first + 1 < count) {
                count = result.first + 1;
                bonus = result.second + 1;
            } else if(result.first + 1 == count) {
                if(result.second + 1 >= bonus) {
                    count = result.first + 1;
                    bonus = result.second + 1;
                }
            }
        }
        // 불
        if(50 <= k) {
            auto result = solve(k - 50);
            if(result.first + 1 < count) {
                count = result.first + 1;
                bonus = result.second + 1;
            } else if(result.first + 1 == count) {
                if(result.second + 1 >= bonus) {
                    count = result.first + 1;
                    bonus = result.second + 1;
                }
            }
        }
    }

    return {count, bonus};
}

vector<int> solution(int target) {
    vector<int> answer;
    memset(cacheCount, -1, sizeof(cacheCount));
    memset(cacheBonus, -1, sizeof(cacheBonus));

    auto result = solve(target);
    answer = {result.first, result.second};

    return answer;
}
