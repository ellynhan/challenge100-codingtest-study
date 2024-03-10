//
//  숫자 카드 나누기.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(n)
// 최악시간: 200,000,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/135807

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool allDivide(const vector<int>& a, int k) {
    for(int val: a)
        if(val % k != 0) return false;
    return true;
}

bool allUndivide(const vector<int>& a, int k) {
    for(int val: a)
        if(val % k == 0) return false;
    return true;
}

bool solve(const vector<int>& a, const vector<int>& b, int k) {
    return allDivide(a, k) && allUndivide(b, k);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int n = int(arrayA.size());
    int m = int(arrayB.size());
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());

    int a = arrayA[0];
    int b = arrayB[0];

    for(int i = a; i >= 1; i--) {
        if(a % i == 0 && solve(arrayA, arrayB, i)) {
            answer = i;
            break;
        }
    }

    for(int i = b; i >= 1; i--) {
        if(b % i == 0 && solve(arrayB, arrayA, i)) {
            answer = max(answer, i);
            break;
        }
    }

    return answer;
}
