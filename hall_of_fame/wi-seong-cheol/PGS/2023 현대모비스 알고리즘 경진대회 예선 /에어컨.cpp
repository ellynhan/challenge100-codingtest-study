//
//  에어컨.cpp
//  main
//
//  Created by wi_seong on 2/10/24.
//

// 시간복잡도: O(n)
// 최악시간: 50,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/214289#

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int INF = 1e9 + 7;
int outTemperature;
int T1, T2, A, B;
int cache[51][1001];

bool isPossible(int p, int temperature) {
    return (p == 1 && T1 <= temperature && temperature <= T2) || p == 0;
}

bool OOB(int temperature) {
    return temperature < -10 || 40 < temperature;
}

int solve(int k, int temperature, const vector<int>& onboard) {
    if(k == int(onboard.size()) - 1) return 0;
    if(OOB(temperature)) return INF;
    int &ret = cache[temperature + 10][k];
    if(ret != -1) return ret;
    ret = INF;

    if(isPossible(onboard[k + 1], temperature + 1)) {
        int result = solve(k + 1, temperature + 1, onboard);
        if(result == INF) {
        } else if(temperature < outTemperature) {
            ret = min(ret, result);
        } else {
            ret = min(ret, result + A);
        }
    }
    if(isPossible(onboard[k + 1], temperature - 1)) {
        int result = solve(k + 1, temperature - 1, onboard);
        if(result == INF) {
        } else if(temperature > outTemperature) {
            ret = min(ret, result);
        } else {
            ret = min(ret, result + A);
        }
    }
    if(isPossible(onboard[k + 1], temperature)) {
        int result = solve(k + 1, temperature, onboard);
        if(result == INF) {
        } else if(temperature == outTemperature) {
            ret = min(ret, result);
        } else {
            ret = min(ret, result + B);
        }
    }

    return ret;
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = 0;
    memset(cache, -1, sizeof(cache));
    outTemperature = temperature;
    T1 = t1;
    T2 = t2;
    A = a;
    B = b;

    answer = solve(0, temperature, onboard);

    return answer;
}
