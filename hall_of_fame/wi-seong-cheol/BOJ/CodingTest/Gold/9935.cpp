//
//  9935.cpp
//  main
//
//  Created by wi_seong on 2023/03/23.
//

/*
 [Input]
 mirkovC4nizCC44
 C4
 [Output]
 mirkovniz
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/9935

#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<char> result;
string str, exp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str >> exp;
    int exp_len = (int)exp.size();
    for(char c: str) {
        result.push_back(c);
        
        if(result.size() >= exp_len && equal(exp.rbegin(), exp.rend(), result.rbegin())) {
            result.resize(result.size() - exp_len);
        }
    }
    if(result.empty()) cout << "FRULA";
    else {
        for(char c: result)
            cout << c;
    }
    
    return 0;
}
