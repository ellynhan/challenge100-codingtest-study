//
//  큰 수 만들기.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(nlogk)
// 최악시간: 6,000,000
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42883#

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    while(k--) {
        int len = int(number.size());
        bool isRemove = false;
        for(int i = 0; i < len - 1; i++) {
            if(number[i] < number[i + 1]) {
                number.erase(number.begin() + i);
                isRemove = true;
                break;
            }
        }
        if(!isRemove) number.pop_back();
    }

    string answer = number;

    return answer;
}
