//
//  양궁대회.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/22/24.
//

// 시간복잡도: O(2 ^ n)
// 최악시간: 2,048
// 난이도: Level 2
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92342

#include <iostream>
#include <vector>

using namespace std;
int dif;
int N;
vector<int> answer;
vector<int> result(11), a(11);

void solve(int k, int cnt) {
    if(k == N) {
        int asum = 0;
        int bsum = 0;
        for(int i = 0; i <= 10; i++) {
            if(result[i] == 0 && a[i] == 0) continue;
            if(result[i] > a[i]) {
                asum += i;
            } else {
                bsum += i;
            }
        }
        if(dif < asum - bsum) {
            dif = asum - bsum;
            answer.clear();
            for(int i = 10; i >= 0; i--) {
                answer.push_back(result[i]);
            }
        }
        return;
    }

    for(int i = cnt; i <= 10; i++) {
        if(a[i] >= result[i]) {
            result[i]++;
            solve(k + 1, i);
            result[i]--;
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    for(int i = 10; i >= 0; i--)
        a[10 - i] = info[i];
    solve(0, 0);
    if(answer.empty()) return {-1};
    return answer;
}
