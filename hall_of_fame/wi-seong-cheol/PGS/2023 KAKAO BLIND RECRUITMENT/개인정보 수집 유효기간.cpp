//
//  개인정보 수집 유효기간.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/24.
//

// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Level 1
// Timer: 40h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/150370

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    vector<int> privacy_data;
    unordered_map<char, int> term_data;
    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 2));
    int day = stoi(today.substr(8, 2));
    int current = (((year * 12) + month) * 28) + day;
    
    for(string str: terms) {
        stringstream ss(str);
        char type;
        int due;
        ss >> type >> due;
        term_data[type] = due;
    }
    
    for(int i = 0; i < privacies.size(); i++) {
        string str = privacies[i];
        year = stoi(str.substr(0, 4));
        month = stoi(str.substr(5, 2));
        day = stoi(str.substr(8, 2));
        char type = str.back();
    
        int total = (((year * 12) + month + term_data[type]) * 28) + day;
        
        if(current >= total)
            answer.push_back(i + 1);
    }
    
    return answer;
}
