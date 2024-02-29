//
//  광물 캐기.cpp
//  main
//
//  Created by wi_seong on 2/15/24.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(3 ^ n)
// 최악시간: 59,049
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/172927

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
const int INF = 1e9 + 7;
int answer;
int chart[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
unordered_map<string, int> m = {{"diamond", 0}, {"iron", 1}, {"stone", 2}};

bool isExit(const int& k, const vector<int>& picks, const vector<string>& minerals) {
    bool allUsed = true;
    for(int pick: picks)
        if(pick != 0) allUsed = false;
    return allUsed || k == int(minerals.size());
}

void solve(int k, int stamina, vector<int>& picks, vector<string>& minerals) {
    if(isExit(k, picks, minerals)) {
        answer = min(answer, stamina);
        return;
    }

    for(int i = 0; i < int(picks.size()); i++) {
        if(picks[i] == 0) continue;
        int sum = 0;
        int len = min(5, int(minerals.size()) - k);
        for(int j = 0; j < len; j++) {
            int idx = m[minerals[k + j]];
            sum += chart[i][idx];
        }
        picks[i]--;
        stamina += sum;
        solve(k + len, stamina, picks, minerals);
        stamina -= sum;
        picks[i]++;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    answer = INF;
    solve(0, 0, picks, minerals);

    return answer;
}
