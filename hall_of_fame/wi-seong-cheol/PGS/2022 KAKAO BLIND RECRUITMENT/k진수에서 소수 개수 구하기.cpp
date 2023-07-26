//
//  k진수에서 소수 개수 구하기.cpp
//  main
//
//  Created by wi_seong on 2023/02/27.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92335#

#include <string>
#include <vector>
#include <sstream>

using namespace std;
#define ull unsigned long long

bool is_prime(ull n) {
    if(n <= 1) return false;
    for(ull i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

string trans(int n, int k) {
    if(k == 0) return "0";
    string ret = "";
    while(n) {
        ret = to_string(n % k) + ret;
        n /= k;
    }
    return ret;
}

int solution(int n, int k) {
    int answer = 0;
    vector<ull> target;
    string p, token;
    
    string nBase = trans(n, k);
    stringstream sstream(nBase);
    while(getline(sstream, token, '0'))
        if(token != "") target.push_back(stoull(token));
    for(ull x: target)
        if(is_prime(x)) answer++;
    
    return answer;
}
