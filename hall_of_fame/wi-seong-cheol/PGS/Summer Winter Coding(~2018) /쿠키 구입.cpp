//
//  쿠키 구입.cpp
//  main
//
//  Created by wi_seong on 2/1/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 4,000,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/49995#

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int n = int(cookie.size());

    for(int i = 0; i < cookie.size() - 1; i++){
        int leftSum = cookie[i];
        int rightSum = cookie[i + 1];
        int left = i;
        int right = i + 1;

        while(true){
            if(leftSum == rightSum)
                answer = max(answer, leftSum);

            if(leftSum > rightSum){
                if(right + 1 == n) break;
                rightSum += cookie[++right];
            }
            else{
                if(left - 1 < 0) break;
                leftSum += cookie[--left];
            }
        }
    }

    return answer;
}
