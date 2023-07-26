//
//  단어 퍼즐.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/02.
//

// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Level 4
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12983

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
const int INF = 0x7f7f7f7f;
int d[20001];
unordered_set<string> s;

int solution(vector<string> strs, string t) {
    int answer = 0;
    int n = t.size();

    for(int i = 0; i < n; i++)
        d[i] = INF;
    for(string str: strs)
        s.insert(str);

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 1; j <= n - i && j <= 5; j++) {
            string tmp = t.substr(i, j);
            if(s.find(tmp) != s.end())
                d[i] = min(d[i], d[i + j] + 1);
        }
    }

    if(d[0] == INF) return -1;
    else return d[0];
}
