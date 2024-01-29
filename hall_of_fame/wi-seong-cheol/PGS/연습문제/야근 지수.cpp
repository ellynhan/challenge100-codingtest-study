//
//  야근 지수.cpp
//  main
//
//  Created by wi_seong on 1/29/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12927

#include <vector>
#include <queue>

using namespace std;
priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    for(int work: works) {
        pq.push(work);
    }
    for(int i = 0; i < n; i++) {
        if(pq.empty()) break;
        int val = pq.top(); pq.pop();
        val--;
        if(val == 0) continue;
        pq.push(val);
    }
    while(!pq.empty()) {
        long long val = pq.top(); pq.pop();
        answer += val * val;
    }

    return answer;
}
