//
//  단어 변환.cpp
//  main
//
//  Created by wi_seong on 3/21/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 250
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/43163

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;
int n;
unordered_set<string> s, vis;

int solve(int k, const string& begin, const string& target) {
    queue<pair<string, int>> Q;
    Q.push({begin, 0});
    vis.insert(begin);
    int len = int(begin.length());

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        if(cur.first == target) {
            return cur.second;
        }

        for(int i = 0; i < len; i++) {
            for(int j = 0; j < 26; j++) {
                string str = cur.first;
                str[i] = char('a' + j);
                if(vis.find(str) != s.end()) continue;
                if(str == cur.first || s.find(str) == s.end()) continue;
                vis.insert(str);
                Q.push({str, cur.second + 1});
            }
        }
    }

    return 0;
}

int solution(string begin, string target, vector<string> words) {
    n = int(words.size());
    s = unordered_set(words.begin(), words.end());
    int answer = solve(0, begin, target);

    return answer;
}
