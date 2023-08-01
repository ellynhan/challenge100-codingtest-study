//
//  [1차] 추석 트래픽.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/06.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 4,000,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/17676

#include <string>
#include <vector>
#include <iostream>

using namespace std;
#define X first
#define Y second
// 시작 시간과 종료 시간을 추출
// 시작시간, 끝나는 시간 - 1을 모두 넣어줌
vector<int> start_t, end_t;
vector<pair<int, int>> process;

int timeToInt(string t) {
    int second = 0;
    second += stoi(t.substr(0, 2)) * 60 * 60 * 1000;
    second += stoi(t.substr(3, 2)) * 60 * 1000;
    second += stoi(t.substr(6, 2)) * 1000;
    second += stoi(t.substr(9, 3));
    return second;
}

int processTime(string t) {
    int second = 0;
    second = (t[0] - '0') * 1000;
    if(t.size() > 3)
        second += stoi(t.substr(2, t.size() - 2));
    return second;
}

void parse(string s) {
    int en = timeToInt(s.substr(0, 12));
    int pt = processTime(s.substr(13, s.size() - 13));
    int st = en - pt + 1;
    start_t.push_back(st);
    end_t.push_back(en);
}

int solution(vector<string> lines) {
    int answer = 0;
    
    for(string line: lines)
        parse(line.substr(11, line.size() - 11));
    
    for(int i = 0; i < lines.size(); i++) {
        int end_time = end_t[i] + 1000;
        int cnt = 0;
        
        for(int j = i; j < lines.size(); j++) {
            if(start_t[j] < end_time)
                cnt++;
        }
        
        answer = max(answer, cnt);
    }
    
    return answer;
}
