//
//  징검다리 건너기.cpp
//  main
//
//  Created by wi_seong on 1/30/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 1,000,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/64062

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n;

bool solve(int x, int k, const vector<int>& stones) {
    int len = 0;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(stones[i] - x < 0) {
            cnt++;
        } else {
            cnt = 0;
        }
        len = max(len, cnt);
    }

    return len < k;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    n = int(stones.size());
    int st = 1;
    int en = *max_element(stones.begin(), stones.end());

    while(st <= en) {
        int mid = (st + en) / 2;

        if(solve(mid, k, stones)) {
            st = mid + 1;
            answer = max(answer, mid);
        } else {
            en = mid - 1;
        }
    }

    return answer;
}
