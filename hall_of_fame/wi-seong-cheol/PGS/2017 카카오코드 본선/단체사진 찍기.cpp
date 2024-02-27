//
//  단체사진 찍기.cpp
//  main
//
//  Created by wi_seong on 2/16/24.
//

// 시간복잡도: O(2 ^ 8)
// 최악시간: 40,320
// 난이도: Level 2
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1835

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;
int answer;
unordered_map<char, int> pos;
char characters[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
bool isused[8];

bool isPossible(const string& s) {
    char a = s[0];
    char b = s[2];
    int len = s[4] - '0';

    if(s[3] == '=') {
        return abs(pos[a] - pos[b]) == len + 1;
    } else if(s[3] == '<') {
        return abs(pos[a] - pos[b]) < len + 1;
    } else {
        return abs(pos[a] - pos[b]) > len + 1;
    }
}

void solve(int k, const vector<string>& data) {
    if(k == 8) {
        for(int i = 0; i < int(data.size()); i++) {
            if(!isPossible(data[i])) return;
        }
        answer++;
        return;
    }

    for(int i = 0; i < 8; i++) {
        if(isused[i]) continue;
        isused[i] = true;
        pos.insert({characters[k], i});
        solve(k + 1, data);
        pos.erase(characters[k]);
        isused[i] = false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    pos.clear();
    memset(isused, false, sizeof(isused));

    solve(0, data);

    return answer;
}
