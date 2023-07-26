//
//  [카카오 인턴] 수식 최대화.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/07.
//

// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Level 2
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/67257

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#define ll long long
string exp;
ll ans;
vector<ll> val;
vector<char> op;
bool isused[3];

ll cal(string priority) {
    vector<char> tmp_op = op;
    vector<ll> tmp_val = val;
    
    for(int i = 0; i < 3; i++) {
        char cur = priority[i];
        for(int j = 0; j < tmp_op.size(); j++) {
            if(tmp_op[j] == cur) {
                ll value;
                if(cur == '+')
                    value = tmp_val[j] + tmp_val[j + 1];
                else if(cur == '-')
                    value = tmp_val[j] - tmp_val[j + 1];
                else
                    value = tmp_val[j] * tmp_val[j + 1];
                tmp_op.erase(tmp_op.begin() + j);
                tmp_val.erase(tmp_val.begin() + j, tmp_val.begin() + j + 2);
                tmp_val.insert(tmp_val.begin() + j, value);
                j--;
            }
        }
    }
        
    return abs(tmp_val[0]);
}

void func(int k, string priority) {
    if(k == 3) {
        ans = max(ans, cal(priority));
        return;
    }
    
    for(int i = 0; i < 3; i++) {
        if(!isused[i]) {
            isused[i] = true;
            string nxt_priority = priority;
            if(i == 0) nxt_priority += "+";
            else if(i == 1) nxt_priority += "-";
            else nxt_priority += "*";
            func(k + 1, nxt_priority);
            isused[i] = false;
        }
    }
}

long long solution(string expression) {
    
    int value = 0;
    for(int i = 0; i < expression.size(); i++) {
        if('0' <= expression[i] && expression[i] <= '9')
            value = value * 10 + (expression[i] - '0');
        else {
            val.push_back(value);
            op.push_back(expression[i]);
            value = 0;
        }
    }
    val.push_back(value);

    exp = expression;
    func(0, "");
    
    return ans;
}
