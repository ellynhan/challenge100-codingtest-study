//
//  표현 가능한 이진트리.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/27.
//

// 시간복잡도: O(nlogn)
// 최악시간: 40,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/150367

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string hexToDec(long long n) {
    string ret = "";
    while(n) {
        ret = to_string(n % 2) + ret;
        n /= 2;
    }
    return ret;
}

string changeToFullDec(string str) {
    string ret = str;
    int idx = 2;
    while(1) {
        if(str.length() <= idx - 1) break;
        idx *= 2;
    }
    for(int i = 0; i < idx - 1 - str.length(); i++)
        ret = "0" + ret;
    return ret;
}
 
bool isAllZero(string str) {
    for(char c : str)
        if (c != '0') return false;
    return true;
}
 
bool canDraw(string str) {
    if(str.length() == 1 || isAllZero(str)) return true;
 
    int midIdx = str.length() / 2;
    string left = str.substr(0, midIdx);
    string right = str.substr(midIdx + 1);
 
    if(str[midIdx] == '1' && canDraw(left) && canDraw(right)) return true;
    else return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long& n: numbers) {
        string dec = hexToDec(n);
        string fullDec = changeToFullDec(dec);
        answer.push_back(canDraw(fullDec));
    }
    
    return answer;
}
