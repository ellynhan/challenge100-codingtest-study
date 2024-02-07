//
//  짝지어 제거하기.cpp
//  main
//
//  Created by wi_seong on 2/7/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12973

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    stack<char> st;

    for(char ch: s) {
        if(!st.empty() && ch == st.top()) {
            st.pop();
        } else {
            st.push(ch);
        }
    }

    return st.empty();
}
