//
//  올바른 괄호의 갯수.cpp
//  main
//
//  Created by wi_seong on 2/1/24.
//

// 시간복잡도: O(2 ^ n)
// 최악시간: 16,384
// 난이도: Level 4
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12929

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int answer, N;

void solve(int k, stack<int>& st) {
    if(k == N * 2) {
        answer++;
        return;
    }

    int n = st.size();
    if(n <= (N * 2) - k - 1) {
        st.push(1);
        solve(k + 1, st);
        st.pop();
    }
    if(!st.empty()) {
        st.pop();
        solve(k + 1, st);
        st.push(1);
    }
}

int solution(int n) {
    N = n;
    stack<int> st;
    solve(0, st);

    return answer;
}
