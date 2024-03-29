//
//  소수 찾기.cpp
//  main
//
//  Created by wi_seong on 3/21/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 70,000,000
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42839

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
const int MXN = 10000001;
vector<bool> isPrime(MXN);
unordered_set<int> s;
bool isused[7];

void seive() {
    isPrime[0] = isPrime[1] = true;
    for(int i = 2; i * i < MXN; i++) {
        if(isPrime[i]) continue;
        for(int j = i + i; j <= MXN; j+=i) {
            isPrime[j] = true;
        }
    }
}

void solve(int k, int len, string cur, string numbers) {
    if(k == len) {
        int num = stoi(cur);
        if(!isPrime[num]) {
            s.insert(num);
        }
        return;
    }

    for(int i = 0; i < int(numbers.size()); i++) {
        if(isused[i]) continue;
        isused[i] = true;
        solve(k + 1, len, cur + numbers[i], numbers);
        isused[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    seive();
    int n = int(numbers.size());

    for(int len = 1; len <= n; len++) {
        solve(0, len, "", numbers);
    }
    answer = int(s.size());

    return answer;
}
