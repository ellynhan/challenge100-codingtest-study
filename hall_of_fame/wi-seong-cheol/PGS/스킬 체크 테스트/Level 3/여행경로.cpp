//
//  여행경로.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/02.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000,00
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
int n;
vector<string> answer;
bool vis[100000001];
bool check = false;

void dfs(string airport, vector<vector<string>>& tickets, int count) {
    if(tickets.size() == count) {
        check = true;
    }
    answer.push_back(airport);
    for(int i = 0; i < n; i++) {
        if(vis[i] || tickets[i][0] != airport) continue;
        vis[i] = true;
        dfs(tickets[i][1], tickets,count+1);

        if(!check) {
            answer.pop_back();
            vis[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {

    n = tickets.size();
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, 0);

    return answer;
}
