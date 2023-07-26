//
//  양궁대회.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/27.
//

// 시간복잡도: O(2^n * n)
// 최악시간: 10,240
// 난이도: Level 2
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92342

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
vector<int> answer;
int a[11];
int r[11];

void func(int k, int cnt) {
    if(k == N) {
        int asum = 0;
        int rsum = 0;
        for(int i=0; i <= 10; i++) {
            if(a[i] == r[i] && a[i] == 0) continue;
            if(r[i] > a[i]) rsum += i;
            else asum += i;
        }
        if(ans < rsum - asum) {
            ans = rsum - asum;
            answer.clear();
            for(int i = 10; i >= 0; i--) {
                answer.push_back(r[i]);
            }
        }
    }
    for(int i = cnt; i <= 10; i++) {
        if(a[i] >= r[i]) {
            r[i]++;
            func(k + 1, i);
            r[i]--;
        }
    }
}
vector<int> solution(int n, vector<int> info) {
    N = n;
    for(int i = 10; i >= 0; i--)
        a[10 - i] = info[i];
    func(0, 0);
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}
