//
//  뒤에 있는 큰 수 찾기.cpp
//  main
//
//  Created by wi_seong on 2/10/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/154539

#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = int(numbers.size());
    stack<int> s;

    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty()) {
            if(s.top() <= numbers[i]) s.pop();
            else break;
        }
        if(s.empty()) answer.push_back(-1);
        else answer.push_back(s.top());
        s.push(numbers[i]);
    }
    reverse(answer.begin(), answer.end());

    return answer;
}
