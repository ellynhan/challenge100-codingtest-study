//
//  피보나치 수.cpp
//  main
//
//  Created by wi_seong on 1/29/24.
//

// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Level 2
// Timer: 5m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12945

#include <string>
#include <vector>
#include <cstring>

using namespace std;
const int mod = 1234567;
int cache[100001];

int fibo(int x) {
    int & ret = cache[x];
    if(ret != -1) return ret;
    return ret = (fibo(x - 2) + fibo(x - 1)) % mod;
}

int solution(int n) {
    int answer = 0;
    memset(cache, -1, sizeof(cache));
    cache[0] = 0; cache[1] = 1;
    answer = fibo(n);

    return answer;
}
