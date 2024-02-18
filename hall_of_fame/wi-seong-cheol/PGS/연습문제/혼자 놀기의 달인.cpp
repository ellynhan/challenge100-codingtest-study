//
//  혼자 놀기의 달인.cpp
//  main
//
//  Created by wi_seong on 2/15/24.
//

// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/131130

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool vis[101];

int solution(vector<int> cards) {
    int answer = 0;
    int n = int(cards.size());
    vector<int> s;

    for(int i = 0; i < n; i++) {
        if(vis[i + 1]) continue;
        int cnt = 1;
        int cur = i + 1;
        vis[cur] = true;
        while(true) {
            cur = cards[cur - 1];
            if(vis[cur]) break;
            vis[cur] = true;
            cnt++;
        }
        s.push_back(cnt);
    }
    sort(s.begin(), s.end());
    if(int(s.size()) == 1) return 0;
    int a = s.back(); s.pop_back();
    int b = s.back();
    answer = a * b;

    return answer;
}
