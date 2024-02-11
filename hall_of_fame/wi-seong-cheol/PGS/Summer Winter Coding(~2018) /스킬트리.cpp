//
//  스킬트리.cpp
//  main
//
//  Created by wi_seong on 2/11/24.
//

// 시간복잡도: O(n * m)
// 최악시간: 520
// 난이도: Level 2
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/49993

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int pos = 0;
    unordered_set<char> s;

    for(char ch: skill) {
        s.insert(ch);
    }

    for(string tree: skill_trees) {
        pos = 0;
        bool flag = true;
        for(char ch: tree) {
            if(s.find(ch) != s.end()) {
                if(ch != skill[pos]) {
                    flag = false;
                    break;
                }
                pos++;
            }
        }
        if(flag) answer++;
    }

    return answer;
}
