//
//  할인 행사.cpp
//  main
//
//  Created by wi_seong on 2/10/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/131127

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, int> m;

bool isPossible(const vector<string>& want, const vector<int>& number) {
    int n = int(want.size());
    for(int i = 0; i < n; i++) {
        if(m[want[i]] != number[i]) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int n = int(discount.size());

    for(int i = 0; i < 10; i++) {
        m[discount[i]]++;
    }
    answer += isPossible(want, number);
    for(int i = 10; i < n; i++) {
        m[discount[i - 10]]--;
        m[discount[i]]++;
        answer += isPossible(want, number);
    }

    return answer;
}
