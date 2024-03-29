//
//  모의고사.cpp
//  main
//
//  Created by wi_seong on 3/21/24.
//

// 시간복잡도: O(n)
// 최악시간: 30,000
// 난이도: Level 1
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<vector<int>> a = {
    {1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5},
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
};

int answerCount(int idx, const vector<int>& answer) {
    int cnt = 0;
    int m = int(a[idx].size());
    for(int i = 0; i < n; i++) {
        if(answer[i] == a[idx][i % m]) {
            cnt++;
        }
    }
    return cnt;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int>> v;
    n = int(answers.size());

    for(int i = 0; i < 3; i++) {
        int cnt = answerCount(i, answers);
        v.push_back({cnt, i + 1});
    }
    sort(v.begin(), v.end(), greater<>());
    answer.push_back(v[0].second);
    int val = v[0].first;
    for(int i = 1; i < 3; i++) {
        if(v[i].first == val) {
            answer.push_back(v[i].second);
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}
