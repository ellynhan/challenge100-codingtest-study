//
//  JadenCase 문자열 만들기.cpp
//  main
//
//  Created by wi_seong on 2/7/24.
//

// 시간복잡도: O(n)
// 최악시간: 200
// 난이도: Level 2
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12951

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = " " + s;
    int len = int(answer.length());

    for(int i = 1; i < len; i++) {
        char& ch = answer[i];
        if(answer[i - 1] == ' ' && 'a' <= ch && ch <= 'z') {
            ch += 'A' - 'a';
        } else if(answer[i - 1] != ' ' && 'A' <= ch && ch <= 'Z') {
            ch -= 'A' - 'a';
        }
    }
    answer.erase(answer.begin(), answer.begin() + 1);

    return answer;
}
