//
//  불량 사용자.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/30/24.
//

// 시간복잡도: O(2 ^ n)
// 최악시간: 1,024
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/64064

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
unordered_set<int> s;
int n;

bool isFind(const string& s1, const string& s2) {
    int len = int(s1.length());
    if(s1.length() == s2.length()) {
        for(int i = 0; i < len; i++) {
            if(s1[i] == s2[i] || s1[i] == '*')
                continue;
            return false;
        }
    } else {
        return false;
    }
    return true;
}

void solve(int k, int selected, const vector<string>& user_id, const vector<string>& banned_id) {
    if(k == int(banned_id.size())) {
        s.insert(selected);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(selected & (1 << i)) continue;
        if(!isFind(banned_id[k], user_id[i])) continue;
        selected |= (1 << i);
        solve(k + 1, selected, user_id, banned_id);
        selected -= (1 << i);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    n = int(user_id.size());

    solve(0, 0, user_id, banned_id);
    int answer = s.size();

    return answer;
}
