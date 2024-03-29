//
//  [카카오 인턴] 수식 최대화.cpp
//  main
//
//  Created by wi_seong on 3/21/24.
//

// 시간복잡도: O(n * 2 ^ k)
// 최악시간: 800
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/67257

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> number;
vector<char> exp;

long long solution(string expression) {
    long long answer = 0;
    string op = "+-*";

    string num = "";
    for(char ch: expression) {
        if('0' <= ch && ch <= '9') {
            num += ch;
        } else {
            number.push_back(stoll(num));
            exp.push_back(ch);
            num = "";
        }
    }
    number.push_back(stoll(num));

    vector<int> brute = {0, 1, 2};

    do {
        vector<long long> tmpVal = number;
        vector<char> tmpExp = exp;

        for(int i = 0; i < 3; i++) {
            char e = op[brute[i]];
            for(int i = 0; i < int(tmpVal.size()) - 1; i++) {
                if(tmpExp[i] != e) continue;
                if(e == '+') {
                    tmpVal[i] += tmpVal[i + 1];
                } else if(e == '-') {
                    tmpVal[i] -= tmpVal[i + 1];
                } else {
                    tmpVal[i] *= tmpVal[i + 1];
                }
                tmpExp.erase(tmpExp.begin() + i);
                tmpVal.erase(tmpVal.begin() + i + 1);
                i--;
            }
        }
        answer = max(answer, abs(tmpVal[0]));
    } while(next_permutation(brute.begin(), brute.end()));

    return answer;
}
