//
//  매칭 점수.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/03.
//

// 시간복잡도: O()
// 최악시간:
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42893#

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
// 링크점수 = 기본점수 / 외부링크수
struct PAGE {
    int idx;
    int basicPoint;
    vector<string> linkList;
    double linkPoint;
    double matchPoint;
};

string keyword;
map<string, int> pageNum;
vector<PAGE> Page;

bool cmp(PAGE A , PAGE B) {
    if(A.matchPoint >= B.matchPoint) {
        if(A.matchPoint == B.matchPoint) {
            if(A.idx < B.idx) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

// 대소문자 구분이 없기 때문에 문자열을 모두 대문자로
string toUpper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// URL 구하기
string findURL(string str) {
    string target = "<META PROPERTY=\"OG:URL\" CONTENT=\"HTTPS://";
    int idx = str.find(target);
    idx += target.length();
    string URL = "";
    while(str[idx] != '\"')
        URL += str[idx++];
    return URL;
}

// 기본 점수 계산
int findWord(string str) {
    int basicPoint = 0;
    string cur = "";
    string target1 = "<BODY>";
    string target2 = "/<BODY>";
    int idx1 = str.find(target1);
    idx1 += target1.length();
    int idx2 = str.find(target2);
    str = str.substr(idx1, idx2 - idx1);
 
    for(int i = 0; i < str.length(); i++) {
        if(isalpha(str[i]) == 0) {
            if(cur == keyword) basicPoint++;
            cur = "";
        } else {
            cur += str[i];
        }
    }
    return basicPoint;
}

// 외부 링크 수 계산
vector<string> findLink(string str) {
    vector<string> result;
    string target = "<A HREF=\"HTTPS://";
    int idx = str.find(target);
    
    while(idx != -1) {
        idx += target.length();
        string cur = "";
        while(str[idx] != '\"')
            cur += str[idx++];
        result.push_back(cur);
        str = str.substr(idx);
        idx = str.find(target);
    }
    
    return result;
}
 
void calLinkPoint() {
    for(int i = 0; i < Page.size(); i++) {
        vector<string> v = Page[i].linkList;
        int size = v.size();
        for(int j = 0; j < v.size(); j++) {
            string str = v[j];
            if(pageNum[str] == 0) continue;
            int targetIdx = pageNum[str] - 1;
            Page[targetIdx].linkPoint += ((double)Page[i].basicPoint / (double)size);
        }
    }
    for (int i = 0; i < Page.size(); i++)
        Page[i].matchPoint = (double)Page[i].basicPoint + (double)Page[i].linkPoint;
    
    sort(Page.begin(), Page.end(), cmp);
}

int solution(string word, vector<string> pages) {
    int n = pages.size();
    keyword = toUpper(word);
    
    for (int i = 0; i < n; i++) {
        string str = toUpper(pages[i]);  // 페이지를 모두 소문자로 변환
        string URL = findURL(str);
        pageNum[URL] = i + 1;
        int basicPoint = findWord(str);
        vector<string> links = findLink(str);
        Page.push_back({i, basicPoint, links, 0.0, 0.0});
    }
    calLinkPoint();
    
    int answer = Page[0].idx;
    
    return answer;
}
