//
//  상담원 인원.cpp
//  main
//
//  Created by wi_seong on 2/7/24.
//

// 시간복잡도: O((n * k) ^ 2)
// 최악시간: 10,000
// 난이도: Level 3
// Timer: 40m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/214288#

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcWait(int k, const vector<int>& p, const vector<vector<int>>& reqs) {
    vector<int> v[k];
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < p[i]; j++)
            v[i].push_back(0);
    }
    int a, b, c;
    int wait = 0;

    for(auto req: reqs) {
        a = req[0];
        b = req[1];
        c = req[2] - 1;

        sort(v[c].begin(), v[c].end());

        if(v[c][0] == 0) {
            v[c][0] = a + b;
        } else {
            if(v[c][0] - a <= 0) {
                v[c][0] = a + b;
            } else {
                wait += v[c][0] - a;
                v[c][0] += b;
            }
        }
    }

    return wait;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;

    int cnt = k;
    vector<int> p(k, 1);
    int preWait = calcWait(k, p, reqs);

    while(cnt < n) {
        int idx = 0;
        int mnWait = preWait;
        for(int i = 0; i < k; i++) {
            p[i]++;
            int curWait = calcWait(k, p, reqs);
            if(mnWait > curWait) {
                idx = i;
                mnWait = curWait;
            }
            p[i]--;
        }

        cnt++;
        p[idx]++;
        preWait = mnWait;
    }

    answer = preWait;

    return answer;
}
