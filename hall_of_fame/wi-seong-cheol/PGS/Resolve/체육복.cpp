//
//  체육복.cpp
//  main
//
//  Created by wi_seong on 3/21/24.
//

// 시간복잡도: O(n)
// 최악시간: 30
// 난이도: Level 1
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>

using namespace std;
int a[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    for(int val: lost) {
        a[val]--;
    }
    for(int val: reserve) {
        a[val]++;
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] < 0 && a[i - 1] > 0) {
            a[i]++;
            a[i - 1]--;
        } else if(a[i] < 0 && a[i + 1] > 0) {
            a[i]++;
            a[i + 1]--;
        }
    }
    for(int i = 1; i <= n; i++) {
        answer += a[i] >= 0 ? 1 : 0;
    }
    return answer;
}
