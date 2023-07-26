//
//  [3차] 파일명 정렬.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/06.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/17686#

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
struct File {
    string Head;
    int Number;
    int Idx;
};

vector<File> info;

string toUpper(string s) {
    for(int i = 0; i < s.size(); i++)
        s[i] = toupper(s[i]);
    return s;
}

bool cmp(File& a, File& b) {
    string headA = toUpper(a.Head);
    string headB = toUpper(b.Head);
    if(headA == headB) {
        if(a.Number == b.Number)
            return a.Idx < b.Idx;
        else
            return a.Number < b.Number;
    } else {
        return headA < headB;
    }
}

void parse(string s, int idx) {
    string head;
    int num;
    
    for(int i = 0; i < s.size(); i++) {
        if('0' <= s[i] && s[i] <= '9') {
            int num_len = 1;
            for(int j = i + 1; j < s.size(); j++) {
                if(!('0' <= s[j] && s[j] <= '9') || num_len == 5) break;
                num_len++;
            }
            head = s.substr(0, i);
            num = stoi(s.substr(i, num_len));
            info.push_back({head, num, idx});
            return;
        }
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(int i = 0; i < files.size(); i++)
        parse(files[i], i);
    sort(info.begin(), info.end(), cmp);
    for(auto f: info)
        answer.push_back(files[f.Idx]);
    
    return answer;
}
