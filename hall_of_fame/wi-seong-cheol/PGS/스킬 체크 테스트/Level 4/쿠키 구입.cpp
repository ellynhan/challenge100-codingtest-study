//
//  쿠키 구입.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/02.
//

// 시간복잡도: O(n * nlogn)
// 최악시간: 12,000,000
// 난이도: Level 4
// Timer: 40m
// Url: https://programmers.co.kr/learn/courses/30/lessons/49995

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;

    for(int i = 0; i < cookie.size() - 1; i++){
        int left_sum = cookie[i];
        int right_sum = cookie[i + 1];
        int l_idx = i;
        int r_idx = i + 1;

        while(true) {
            if(left_sum == right_sum)
                answer = max(answer, left_sum);

            if(left_sum > right_sum){
                if(r_idx + 1 == cookie.size()) break;
                right_sum += cookie[++r_idx];
            } else{
                if(l_idx - 1 < 0) break;
                left_sum += cookie[--l_idx];
            }
        }
    }

    return answer;
}
