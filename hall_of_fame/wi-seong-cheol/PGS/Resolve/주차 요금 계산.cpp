//
//  주차 요금 계산.cpp
//  main
//
//  Created by wi_seong on 3/22/24.
//

// 시간복잡도: O(n ^ )
// 최악시간:
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92341

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;
unordered_map<string, int> m;

int s2i(string str) {
    int t = stoi(str.substr(0, 2)) * 60;
    t += stoi(str.substr(3, 2));
    return t;
}

vector<int> solution(vector<int> fee, vector<string> records) {
    vector<int> answer;
    map<string, int> out;

    for(string record: records) {
        stringstream ss(record);
        string token;
        vector<string> result;

        while(getline(ss, token, ' ')) {
            result.push_back(token);
        }

        int t = s2i(result[0]);
        string number = result[1];
        string type = result[2];

        if(type == "IN") {
            m[number] = t;
        } else {
            int t1 = m[number];
            int t2 = t;
            out[number] += t2 - t1;
            m.erase(number);
        }
    }

    int t2 = s2i("23:59");
    for(auto element: m) {
        int t1 = element.second;
        string number = element.first;
        out[number] += t2 - t1;
    }

    for(auto element: out) {
        int t = element.second;
        int val = fee[1];
        if(t > fee[0])  {
            int remain = t - fee[0];
            val += (ceil((double)remain / (double)fee[2])) * fee[3];
        }
        answer.push_back(val);
    }

    return answer;
}
