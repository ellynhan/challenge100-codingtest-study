//
//  택배 배달과 수거하기.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/27.
//

// 시간복잡도: O(n)
// 최악시간: 200,000
// 난이도: Level 2
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/150369

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int box = 0;
    stack<int> D, P;
    
    for(int element: deliveries)
        D.push(element);
    for(int element: pickups)
        P.push(element);
    
    while(!D.empty() && D.top() == 0)
        D.pop();
    while(!P.empty() && P.top() == 0)
        P.pop();
    
    while(!(D.empty() && P.empty())) {
        answer += max(D.size() * 2, P.size() * 2);
        box = 0;
        
        while(!D.empty() && box <= cap) {
            if(D.top() + box <= cap) {
                box += D.top();
            } else {
                D.top() -= (cap - box);
                break;
            }
            D.pop();
        }
        
        box = 0;
        while(!P.empty() && box <= cap) {
            if(P.top() + box <= cap) {
                box += P.top();
            } else {
                P.top() -= (cap - box);
                break;
            }
            P.pop();
        }
    }
    
    return answer;
}
