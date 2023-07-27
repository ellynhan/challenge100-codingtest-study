//
//  최고의 집합.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/02.
//

// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12938

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int mid = s / n;
    if(mid == 0) {
        answer.push_back(-1);
        return answer;
    }
    for(int i = 0; i < n; i++)
        answer.push_back(mid);
    for(int i = 0; i < s % n; i++)
        answer[i] += 1;
    sort(answer.begin(), answer.end());
    
    return answer;
}
