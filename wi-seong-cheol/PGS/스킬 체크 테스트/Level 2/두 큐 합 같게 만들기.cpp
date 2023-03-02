//
//  두 큐 합 같게 만들기.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/02.
//

// 시간복잡도: O(2L)
// 최악시간: 600,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/118667

#include <string>
#include <vector>
#include <queue>

using namespace std;
#define ll long long

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    ll sum1, sum2;
    deque<int> q1, q2;
    sum1 = sum2 = 0;
    for(int q: queue1) {
        sum1 += q;
        q1.push_back(q);
    }
    for(int q: queue2) {
        sum2 += q;
        q2.push_back(q);
    }
    if((sum1 + sum2) % 2 == 1) return -1;
    int t = q1.size() + q2.size() + 2;
    while(sum1 != sum2) {
        if(answer > t + 2) return -1;
        else if(sum1 > sum2) {
            q2.push_back(q1.front());
            sum2 += q1.front();
            sum1 -= q1.front();
            q1.pop_front();
        } else {
            q1.push_back(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop_front();
        }
        answer++;
    }

    return answer;
}
