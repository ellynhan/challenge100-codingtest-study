//
//  가장 긴 팰린드롬.cpp
//  main
//
//  Created by wi_seong on 1/30/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 6,250,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12904

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
const int MXN = 2501;
int cache[MXN][MXN];

bool isPalindrom(const string& s, int st, int en) {
    if(st == en) return 1;
    if(st + 1 == en) return s[st] == s[en];
    int &ret = cache[st][en];
    if(ret != -1) return ret;
    if(s[st] != s[en]) return ret = 0;
    ret = isPalindrom(s, st + 1, en - 1);

    return ret;
}


int solve(const string& s) {
    int ret = 1;
    int n = int(s.size());

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(isPalindrom(s, i, j)) {
                ret = max(ret, j - i + 1);
            }
        }
    }

    return ret;
}

int solution(string s) {
    memset(cache, -1, sizeof(cache));

    int answer = solve(s);

    return answer;
}
