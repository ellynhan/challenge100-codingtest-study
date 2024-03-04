//
//  문자열의 아름다움.cpp
//  main
//
//  Created by wi_seong on 2/20/24.
//

// 시간복잡도: O(n)
// 최악시간: 300,000
// 난이도: Level 5
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/68938

#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

long long solution(string s) {
    unordered_map<char, map<int, int>> lumps;

    int count = 1;
    for(int i = 1; i <= s.length(); ++i) {
        if(i == s.length() || s[i] != s[i-1]) {
            lumps[s[i-1]][count]++;
            count = 1;
        } else {
            ++count;
        }
    }

    long long n = s.length();
    long long unpretty = (n - 1) * n * (n + 1) / 6;

    for(auto& lump : lumps) {
        long long total = 0;
        long long both_side = 0;
        for(auto& [length, num] : lump.second) {
            total += length * num;
            both_side += num;
        }

        for(int i = 1; i <= lump.second.rbegin()->first; ++i) {
            unpretty -= total * (total - 1) / 2;
            total -= both_side;
            both_side -= lump.second[i];
        }
    }

    return unpretty;
}
