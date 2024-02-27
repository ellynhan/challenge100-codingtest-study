//
//  디펜스 게임.cpp
//  main
//
//  Created by wi_seong on 2/15/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/142085

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    int len = int(enemy.size());

    for(int i = 0; i < len; i++) {
        if(int(pq.size()) < k) {
            pq.push(-enemy[i]);
        } else {
            if(pq.top() > -enemy[i]) {
                int val = pq.top(); pq.pop();
                pq.push(-enemy[i]);
                n += val;
            } else {
                n -= enemy[i];
            }
            if(n < 0) break;
        }
        answer++;
    }

    return answer;
}
