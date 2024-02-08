//
//  여행경로.cpp
//  main
//
//  Created by wi_seong on 2/1/24.
//

// 시간복잡도: O(n * m)
// 최악시간: 10,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer;
int n, cnt;
bool vis[10001], flag;

void solve(string cur, const vector<vector<string>>& tickets) {
    if(cnt == tickets.size()) flag = true;
    answer.push_back(cur);

    for(int i = 0; i < n; i++) {
        if(vis[i] || tickets[i][0] != cur) continue;
        vis[i] = true;
        cnt++;
        solve(tickets[i][1], tickets);

        if(!flag) {
            answer.pop_back();
            vis[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    n = int(tickets.size());
    sort(tickets.begin(), tickets.end());

    solve("ICN", tickets);

    return answer;
}
