//
//  같은 숫자는 싫어.cpp
//  main
//
//  Created by wi_seong on 2022/11/07.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 1
// Timer: 5m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12906

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    stack<int> S;
    S.push(arr[0]);
    answer.push_back(arr[0]);
    for(size_t i = 1; i < arr.size(); i++) {
        if(S.top() != arr[i]) {
            S.push(arr[i]);
            answer.push_back(arr[i]);
        }
    }
    return answer;
}
