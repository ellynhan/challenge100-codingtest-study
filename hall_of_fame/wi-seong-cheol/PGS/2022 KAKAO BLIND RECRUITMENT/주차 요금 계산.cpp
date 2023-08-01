//
//  주차 요금 계산.cpp
//  main
//
//  Created by wi_seong on 2023/02/27.
//

// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92341

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> r;             // 기록
    map<string, int> total_time;    // 누적 주차 시간
    
    for(string record: records) {
        vector<string> v;
        istringstream ss(record);
        string token;
        while(getline(ss, token, ' '))
            v.push_back(token);
        int h = stoi(v[0].substr(0, 2));
        int m = stoi(v[0].substr(3, 2));
        int t = h * 60 + m;
        
        if(v[2] == "IN")
            r[v[1]] = t;
        else {
            total_time[v[1]] += t - r[v[1]];
            r.erase(v[1]);
        }
    }
    for(auto element: r) {
        total_time[element.first] += (23 * 60 + 59) - element.second;
    }
    for(auto element: total_time) {
        if(element.second <= fees[0]) {
            answer.push_back(fees[1]);
        } else {
            answer.push_back(fees[1] + ((element.second - fees[0]) / fees[2]) * fees[3] + ((element.second - fees[0]) % fees[2] != 0) * fees[3]);
        }
    }
    
    return answer;
}
