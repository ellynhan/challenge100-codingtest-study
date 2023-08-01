//
//  [1치] 셔틀버스.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/06.
//

// 시간복잡도: O(n)
// 최악시간: 2,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/17678

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

int s2i(string t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}

string i2s(int t) {
    string ret = "";
    if(t / 60 < 10) ret += "0" + to_string(t / 60);
    else ret += to_string(t / 60);
    ret += ":";
    if(t % 60 < 10) ret += "0" + to_string(t % 60);
    else ret += to_string(t % 60);
    return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<vector<int>> bus(n + 1);     // bus[i]는 i번째 버스를 타는 크루들이 도착한 시간 (오름차순)
    int limit = s2i("09:00");           // 버스 도착 시간
    int num = 1;                        // 운행 횟수
    int cnt = 0;                        // 버스에 탄 크루의 수
    int crew;                           // 크루가 도착한 시간
    
    sort(timetable.begin(), timetable.end());
    
    for(string time: timetable) {
        crew = s2i(time);
        
        while(limit < crew || cnt == m) {
            num++;
            cnt = 0;
            limit += t;
        }
        
        if(num > n) break;
        
        bus[num].push_back(crew);
        cnt++;
    }
    
    if(bus[n].size() == m) {
        answer = i2s(bus[n].back() - 1);
    } else {
        answer = i2s(s2i("09:00") + (n - 1) * t);
    }
    
    return answer;
}
