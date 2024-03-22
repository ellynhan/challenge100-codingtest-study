//
//  k진수에서 소수 개수 구하기.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/22/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92335

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(long long number) {
    if(number <= 1) return false;
    for(long long i = 2; i * i <= number; i++) {
        if(number % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    long long answer = 0;

    string num = "";
    while(n) {
        num += to_string(n % k);
        n /= k;
    }
    reverse(num.begin(), num.end());
    string val = "";
    for(char ch: num) {
        if(ch == '0') {
            if(!val.empty() && isPrime(stoll(val))) {
                answer++;
            }
            val = "";
        } else {
            val += ch;
        }
    }
    if(!val.empty() && isPrime(stoll(val))) answer++;

    return answer;
}
