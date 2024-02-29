//
//  단어 퍼즐.cpp
//  main
//
//  Created by wi_seong on 2/5/24.
//

// 시간복잡도: O(n * L)
// 최악시간: 2,000,000
// 난이도: Level 4
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12983

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
const int INF = 1e9 + 7;
int cache[20001];

int solve(const vector<string>& puzzles, string& target, int k) {
    if(target.length() == k) return 0;
    int &ret = cache[k];
    if(ret != -1) return ret;
    ret = INF;

    for(string puzzle: puzzles) {
        int len = int(puzzle.length());
        bool isSame = true;
        for(int i = 0; i < len; i++) {
            if(target[k + i] != puzzle[i]) {
                isSame = false;
                break;
            }
        }

        if(isSame) {
            int result = solve(puzzles, target, k + len);
            if(result == INF) continue;
            ret = min(ret, result + 1);
        }
    }

    return ret;
}

int solution(vector<string> strs, string t) {
    memset(cache, -1, sizeof(cache));
    int answer = solve(strs, t, 0);

    if(answer == INF) return -1;
    return answer;
}
