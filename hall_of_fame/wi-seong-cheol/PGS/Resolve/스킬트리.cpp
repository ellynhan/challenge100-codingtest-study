//
//  스킬트리.cpp
//  main
//
//  Created by wi_seong on 3/19/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 260
// 난이도: Level 2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/49993

#include <string>
#include <vector>

using namespace std;
int level[26];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int n = int(skill.size());
    for(int i = 0; i < n; i++) {
        level[skill[i] - 'A'] = i + 1;
    }

    for(auto tree: skill_trees) {
        bool flag = true;
        int L = 1;
        for(char ch: tree) {
            if(level[ch - 'A'] < L) continue;
            if(level[ch - 'A'] == L) {
                L++;
                continue;
            }
            flag = false;
            break;
        }
        if(flag) answer++;
    }

    return answer;
}
