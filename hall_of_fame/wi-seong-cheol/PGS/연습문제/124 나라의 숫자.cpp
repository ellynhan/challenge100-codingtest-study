//
//  124 나라의 숫자.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(logn)
// 최악시간: 10
// 난이도: 30m
// Timer: Level 2
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12899#

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
unordered_map<int, string> m = {{0, "4"}, {1, "1"}, {2, "2"}};

string solution(int n) {
    string answer = "";
    int val = 1;

    while(n) {
        if(n % 3 == 0) {
            answer += m[n % 3];
            n = n / 3 - 1;
        } else {
            answer += m[n % 3];
            n = n / 3;
        }
    }
    reverse(answer.begin(), answer.end());

    return answer;
}
