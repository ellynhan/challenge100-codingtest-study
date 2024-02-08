//
//  최솟값 만들기.cpp
//  main
//
//  Created by wi_seong on 1/29/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 3,000
// 난이도: Level 2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12941

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int n = int(A.size());

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    for(int i = 0; i < n; i++) {
        answer += A[i] * B[i];
    }

    return answer;
}
