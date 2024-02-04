//
//  110 옮기기.cpp
//  main
//
//  Created by wi_seong on 2/1/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/77886#

#include <iostream>
#include <vector>

using namespace std;

void appendOne(string& s, int& k) {
    while(k) {
        s += '1';
        k--;
    }
}

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for(string str: s) {
        string result = "";
        int countOne = 0;
        int ooz = 0;
        for(char ch: str) {
            if(ch == '0') {
                if(countOne < 2) {
                    appendOne(result, countOne);
                    result.push_back('0');
                } else {
                    ooz++;
                    countOne -= 2;
                }
            } else {
                countOne++;
            }
        }

        while(ooz) {
            result += "110";
            ooz--;
        }
        appendOne(result, countOne);
        answer.push_back(result);
    }
    return answer;
}
