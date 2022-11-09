//
//  프린터.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/09.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(nlogn)
// 최악시간: 200
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
#define X first
#define Y second

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> Q;
    priority_queue<int> pq;
    for(size_t i = 0; i < priorities.size(); i++) {
        Q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    int cnt = 0;
    while(!Q.empty()) {
        int idx = Q.front().X;
        int val = Q.front().Y;
        Q.pop();
        if(pq.top() == val) {
            pq.pop();
            cnt++;
            if(idx == location) {
                answer = cnt;
                break;
            }
        } else {
            Q.push(make_pair(idx, val));
        }
    }
    
    return answer;
}
