//
//  [3차] 방금그곡.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/06.
//

// 시간복잡도: O(n * n)
// 최악시간: 150,000
// 난이도: Level 2
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/17683

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int s2i(string s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

string change(string& str, map<string, char> &s) {
    string ret = "";
    
    for(int i = 0; i < str.size(); i++) {
        if(str[i + 1] == '#') {
            ret += s[str.substr(i, 2)];
            i++;
        }
        else ret += str[i];
    }
    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int bTime = 0;
    map<string, char> s;
    
    s["C#"] = 'Q';
    s["D#"] = 'W';
    s["F#"] = 'R';
    s["G#"] = 'T';
    s["A#"] = 'Y';
    
    string melody = change(m, s);
    
    for(string info: musicinfos) {
        stringstream ss(info);
        string token;
        vector<string> v;
        while(getline(ss, token, ','))
            v.push_back(token);
        int st = s2i(v[0]);
        int en = s2i(v[1]);
        int time = en - st;
        string title = v[2];
        string sheet = change(v[3], s);
        
        if(sheet.size() < time) {
            string tmp = sheet;
        
            for(int j = 1; j < time / tmp.size(); j++)
                sheet += tmp;
            for(int j = 0; j < time % tmp.size(); j++)
                sheet += tmp[j];
        }
        else sheet = sheet.substr(0, time);
        
        if(sheet.find(melody) != string::npos) {
            if(bTime < time) {
                answer = title;
                bTime = time;
            }
        }
    }
    
    return answer;
}
