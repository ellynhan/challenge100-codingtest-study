//
//  도넛과 막대 그래프.cpp
//  main
//
//  Created by wi_seong on 2/16/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/258711

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int inDeg[1000001], outDeg[1000001];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    int n = 0;

    for(auto edge: edges) {
        outDeg[edge[0]]++;
        inDeg[edge[1]]++;
        n = max(n, max(edge[0], edge[1]));
    }

    for(int i = 1; i <= n; i++) {
        if(outDeg[i] == 0) {
            answer[2]++;
        } else if(outDeg[i] == 2) {
            if(inDeg[i] > 0) answer[3]++;
            else answer[0] = i;
        } else if(outDeg[i] > 2) {
            answer[0] = i;
        }
    }
    answer[1] = outDeg[answer[0]] - answer[2] - answer[3];

    return answer;
}
