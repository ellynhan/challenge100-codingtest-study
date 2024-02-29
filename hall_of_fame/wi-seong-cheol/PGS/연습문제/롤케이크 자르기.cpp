//
//  롤케이크 자르기.cpp
//  main
//
//  Created by wi_seong on 2/11/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/132265

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
int n;
int cntA[1000001], cntB[1000001];

int solution(vector<int> topping) {
    int answer = 0;
    n = int(topping.size());
    unordered_set<int> a, b;

    for(int i = 0; i < n; i++) {
        a.insert(topping[i]);
        cntA[topping[i]]++;
    }

    for(int i = n - 1; i >= 0; i--) {
        cntA[topping[i]]--;
        cntB[topping[i]]++;
        b.insert(topping[i]);
        if(cntA[topping[i]] == 0)
            a.erase(topping[i]);
        answer += (a.size() == b.size());
    }

    return answer;
}
