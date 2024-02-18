//
//  줄 서는 방법.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(n)
// 최악시간: 20
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12936

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll fac(int n) {
    ll ret = 1;
    for(int i = 2; i <= n; i++)
        ret *= i;
    return ret;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    ll val = fac(n);
    k--;

    vector<int> number;
    for(int i = 1; i <= n; i++)
        number.push_back(i);
    while(val != 1) {
        val /= n--;
        int idx = k / val;
        answer.push_back(number[idx]);
        number.erase(number.begin() + idx);
        k %= val;
    }
    answer.push_back(number.back());

    return answer;
}
