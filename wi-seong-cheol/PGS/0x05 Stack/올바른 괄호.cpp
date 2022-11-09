//
//  올바른 괄호.cpp
//  main
//
//  Created by wi_seong on 2022/11/09.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Level 2
// Timer: 5m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s) {
    bool answer = true;

    stack<char> S;
    for(auto ch: s) {
        if(ch == '(') S.push(ch);
        else {
            if(S.empty()) {
                answer = false;
                break;
            }
            if(S.top() == ')') break;
            else S.pop();
        }
    }
    if(!S.empty()) answer = false;
    return answer;
}
