//
//  가장 큰 수.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42746#

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
    if(a + b > b + a) return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> stringNumbers;
    for(int val: numbers)
        stringNumbers.push_back(to_string(val));
    sort(stringNumbers.begin(), stringNumbers.end(), cmp);
    for(string val: stringNumbers) {
        if(answer == "" && val == "0") continue;
        answer += val;
    }

    if(answer == "") return "0";

    return answer;
}
