//
//  카펫.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/21/24.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 6,250,000
// 난이도: Level 2
// Timer: 5m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    for(int i = 3; i < 2500; i++) {
        for(int j = 3; j < 2500; j++) {
            int b = i * 2 + (j - 2) * 2;
            int y = (i - 2) * (j - 2);
            if(brown == b && yellow == y) {
                return {j, i};
            }
        }
    }
    return {0, 0};
}
