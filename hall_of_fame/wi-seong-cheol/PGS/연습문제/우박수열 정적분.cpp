//
//  우박수열 정적분.cpp
//  main
//
//  Created by wi_seong on 2/15/24.
//

// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/134239

#include <iostream>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> num = {k};

    while(num.back() != 1) {
        int val = num.back();
        if(val % 2 == 0) {
            val /= 2;
        } else {
            val *= 3;
            val++;
        }
        num.push_back(val);
    }

    int n = int(num.size()) - 1;

    vector<double> psum(n + 1);
    psum[0] = 0;
    for(int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + (double(num[i] + num[i - 1]) / 2);
    }

    for(auto range: ranges) {
        double val;
        if(n + range[1] >= range[0]) {
            val = psum[n + range[1]] - psum[range[0]];
        } else {
            val = -1;
        }
        answer.push_back(val);
    }

    return answer;
}
