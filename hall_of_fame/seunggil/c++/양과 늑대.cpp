#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 각 노드가 가지고 있는 자식들
// 길이는 노드 갯수
vector<vector<int>> childrens;

// 다음에 갈 수 있는 노드 번호
vector<int> canVisit;

// 방문했던 노드
// 길이는 노드 갯수
vector<bool> visited;

int ans = 0;

void dfs(int sheep, int wolf, const vector<int>& info) {
    ans = max(ans, sheep);

    for (int i = 0, n = canVisit.size(); i < n; i++) {
        int nextNode = canVisit[i];
        bool isSheep = info[nextNode] == 0 ? true : false;

        // 해당 노드로 갈 수 있다.
        if ((isSheep || sheep > wolf + 1) && !visited[nextNode]) {
            int size = childrens[nextNode].size();

            visited[nextNode] = true;
            for (int j = 0; j < size; j++) {
                canVisit.push_back(childrens[nextNode][j]);
            }

            if (isSheep) dfs(sheep + 1, wolf, info);
            else        dfs(sheep, wolf + 1, info);

            visited[nextNode] = false;
            for (int j = 0; j < size; j++) {
                canVisit.pop_back();
            }
        }
    }
}



int solution(vector<int> info, vector<vector<int>> edges) {
    childrens = vector<vector<int>>(info.size());
    visited = vector<bool>(info.size());

    for (const vector<int>& iter : edges) {
        childrens[iter[0]].push_back(iter[1]);
    }

    visited[0] = true;
    for (int i : childrens[0]) {
        canVisit.push_back(i);
    }

    dfs(1, 0, info);

    return ans;
}