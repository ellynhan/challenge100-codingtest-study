//
//  광고 삽입.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/01.
//

// 시간복잡도: O(n)
// 최악시간: 360,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/72414#

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int d[360000];
int sum[360000];

int s2i(string s) {
    return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
}

string numzfill(int x) {
    if(x < 10) return "0" + to_string(x);
    return to_string(x);
}

string i2s(int t) {
    string ret = numzfill(t / 3600) + ":";
    t %= 3600;
    ret += numzfill(t / 60) + ":";
    t %= 60;
    ret += numzfill(t);
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int n, m, st, en;
    
    // 플레이 시간 구하기
    n = s2i(play_time);
    
    // 광고 시간 구하기
    m = s2i(adv_time);
    
    // log를 찍어서 구간 합 구하기
    for(string log: logs) {
        // 시작시간, 끝나는 시간
        st = s2i(log.substr(0, 8));
        en = s2i(log.substr(9, 8));
        d[st]++;
        d[en]--;
    }
    for(int i = 1; i <= n; i++)
        d[i] += d[i - 1];
    // 누적 재생시간이 가장 많은 곳 계산
    long long mxval = 0, curval = 0;
    int mxtime = 0;
    for(int i = 0; i < m; i++)
        curval += d[i];
    mxval = curval;
    for(int i = 1; i <= n - m; i++){
        curval = curval - d[i - 1] + d[i + m -1];
        if(curval > mxval){
            mxval = curval;
            mxtime = i;
        }
    }
    
    return i2s(mxtime);
}
