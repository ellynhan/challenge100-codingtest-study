//
//  [3차] 압축.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/06.
//

// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/17684

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    string tmp = "";
    int idx = 27;
    
    for(int i = 0; i < 26; i++)
        dict[tmp + char('A' + i)] = i + 1;

    while(msg.size()) {
        string w = "";
        char c;
        for(int i = 0; i < msg.size(); i++) {
            c = msg[i];
            if(dict[w + c] == 0)
                break;
            w += c;
        }
        answer.push_back(dict[w]);
        msg.erase(0, w.size());
        dict[w + c] = idx++;
    }
    
    return answer;
}
