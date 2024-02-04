//
//  선입 선출 스케줄링.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/4/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 4,500,000,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12920

#include <iostream>
#include <vector>

using namespace std;

int solve(int t, const vector<int>& cores) {
    if(t == 0) return cores.size();
    int cnt = int(cores.size());

    for(int core: cores) {
        cnt += t / core;
    }

    return cnt;
}

int solution(int n, vector<int> cores) {
    int answer = 0;
    int m = 0;
    int time = 0;

    int st = 0;
    int en = 10000 * n;

    while(st <= en) {
        int mid = (st + en + 1) / 2;

        int cnt = solve(mid, cores);
        if(cnt >= n) {
            en = mid - 1;
            m = cnt;
            time = mid;
        } else {
            st = mid + 1;
        }
    }

    m -= n;
    for(int i = int(cores.size()) - 1; i >= 0; i--) {
        if(time % cores[i] == 0) {
            if(m == 0) {
                answer = i + 1;
                break;
            }
            m--;
        }
    }

    return answer;
}
