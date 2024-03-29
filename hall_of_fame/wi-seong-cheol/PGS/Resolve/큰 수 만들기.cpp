//
//  큰 수 만들기.cpp
//  main
//
//  Created by wi_seong on 3/21/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = int(number.size()) - k;

    while(number.size() != n) {
        bool flag = true;
        for(int i = 0; i < int(number.size()) - 1; i++) {
            if(number[i] < number[i + 1]) {
                number.erase(number.begin() + i);
                flag = false;
                break;
            }
        }
        if(flag) number.pop_back();
    }
    answer = number;

    return answer;
}
