//
//  양과 늑대.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/22/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 1,048,576
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92343

#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n;
int answer = 1;
bool vis[1 << 17];
int left[20], right[20];
vector<int> info;

void dfs(int state) {
    if(vis[state]) return;
    vis[state] = 1;

    int w = 0;
    int num = 0;
    for(int i = 0; i < n; i++) {
        if(state & (1 << i)) {
            num++;
            w += info[i];
        }
    }

    if(2 * w >= num) return;

    answer = max(answer, num - w);

    for(int i = 0; i < n; i++) {
        if(!(state & (1 << i))) continue;

        if(left[i] != -1)
            dfs(state | (1 << left[i]));
        if(right[i] != -1)
            dfs(state | (1 << right[i]));
    }
}

int solution(vector<int> _info, vector<vector<int>> edges) {
    info = _info;
    n = int(info.size());
    memset(left, -1, sizeof(left));
    memset(right, -1, sizeof(right));

    for(auto edge: edges) {
        int a = edge[0];
        int b = edge[1];
        if(left[a] == -1) left[a] = b;
        else right[a] = b;
    }
    dfs(1);

    return answer;
}
