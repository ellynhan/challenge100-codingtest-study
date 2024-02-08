//
//  풍선 터뜨리기.cpp
//  main
//
//  Created by wi_seong on 2/1/24.
//

// 시간복잡도: O(n)
// 최악시간: 3,000,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/68646

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int n = int(a.size());
    vector<int> left(n);
    vector<int> right(n);

    int MIN = a[0];
    for(int i = 0; i < n; i++) {
        if(MIN > a[i]) MIN = a[i];
        left[i] = MIN;
    }

    MIN = a[n - 1];
    for(int i = n - 1; i >= 0; i--) {
        if(MIN > a[i]) MIN = a[i];
        right[i] = MIN;
    }

    for(int i = 0; i < n; i++) {
        if(a[i] <= left[i] || a[i] <= right[i]) answer++;
    }

    return answer;
}
