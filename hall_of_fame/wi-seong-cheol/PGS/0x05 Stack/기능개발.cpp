//
//  기능개발.cpp
//  main
//
//  Created by wi_seong on 2022/11/09.
//

// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Level 2
// Timer: 12m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42586
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> S;
    
    for(size_t i = 0; i < progresses.size(); i++) {
        int d = ceil((100 - progresses[i]) / double(speeds[i]));
        while(!S.empty() && S.top() < d) {
            S.pop();
        }
        if(S.empty()) answer.push_back(1);
        else answer.back()++;
        S.push(d);
    }
    
    return answer;
}
