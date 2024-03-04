//
//  브라이언의 고민.cpp
//  main
//
//  Created by wi_seong on 2/10/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Level 3
// Timer: 2h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1830

#include <string>
#include <cctype>
#include <vector>
#include <iostream>

using namespace std;
const string ivd = "invalid";

string rule1(string& str) {
    string ret = "";
    if(int(str.size()) < 3) return "-1";
    char c = str[1];
    bool ok = 0;
    for(int i = 0; i < int(str.size()); i++) {
        if(islower(str[i])) ok = 1;
        if(i % 2 == 0){
            if(islower(str[i])) return "-1";
            ret += str[i];
        } else {
            if(c != str[i]) return "-1";
        }
    }
    if(!ok) return "-1";
    return ret;
}

string allUpper(string& str) {
    string ret = "";
    for(auto c: str) {
        if(!isupper(c)) return "-1";
        ret += c;
    }
    return ret;
}

string solution(string sentence) {
    vector<bool> used(26, 0);
    string answer = "";
    int it = 0;

    while(!sentence.empty()){
        string ret;
        vector<int> pos;

        if(islower(sentence[0])) {
            if(used[sentence[0] - 'a']) return ivd;
            used[sentence[0] - 'a'] = 1;
            for(int i=0; i < int(sentence.size()); i++){
                if(sentence[i] == sentence[0]) {
                    pos.push_back(i);
                }
            }
            if(int(pos.size()) != 2) return ivd;

            string center = sentence.substr(1, pos.back() - 1);
            if(center == "") return ivd;
            ret = rule1(center);
            string target;
            if(ret == "-1") {
                ret = allUpper(center);
                if(ret == "-1") {
                    return ivd;
                }
            } else {
                if(used[sentence[2] - 'a']) return ivd;
                used[sentence[2] - 'a'] = 1;
            }
            sentence = sentence.substr(pos.back() + 1);
        } else {
            if(sentence.size() == 1 || isupper(sentence[1])) {
                ret = sentence[0];
                sentence = sentence.substr(1);
            } else {
                for(int i = 0; i < int(sentence.size()); i++){
                    if(sentence[1] == sentence[i]) pos.push_back(i);
                }

                if(pos.size() != 2) {
                    if(pos.back() == int(sentence.size()) - 1) return ivd;
                    if(islower(sentence[pos.back() + 1])) return ivd;
                    string center = sentence.substr(0, pos.back() + 2);
                    ret = rule1(center);
                    if(ret == "-1") return ivd;
                    if(used[sentence[1] - 'a']) return ivd;
                    used[sentence[1] - 'a'] = 1;
                    sentence = sentence.substr(pos.back() + 2);
                } else {
                    ret = sentence[0];
                    sentence = sentence.substr(1);
                }
            }
        }
        answer += ret+" ";
    }

    answer.pop_back();

    return answer;
}
