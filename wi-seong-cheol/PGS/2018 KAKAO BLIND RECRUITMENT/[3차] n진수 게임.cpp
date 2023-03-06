//
//  [3차] n진수 게임.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/06.
//

// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/17687

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string number = "0123456789ABCDEF";

string number_to_n(int num, int n){
    string result;
    if(num == 0){
        return "0";
    }
    while(num > 0){
        result += number[num % n];
        num /= n;
    }
    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "";
    int size = m * t;
    
    for(int i = 0; tmp.size() <= size; i++) {
        string num = number_to_n(i, n);
        tmp += num;
    }

    for(int i = 0; i < t; i++)
        answer += tmp[(m * i) + (p - 1)];
    
    return answer;
}
