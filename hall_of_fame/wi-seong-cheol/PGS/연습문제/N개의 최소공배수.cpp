//
//  N개의 최소공배수.cpp
//  main
//
//  Created by wi_seong on 2/8/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 200
// 난이도: Level2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12953

#include <string>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;

    sort(arr.begin(), arr.end());
    while(arr.size() != 1) {
        int a = arr.back(); arr.pop_back();
        int b = arr.back(); arr.pop_back();

        arr.push_back(lcm(a, b));
    }
    answer = arr.front();

    return answer;
}
