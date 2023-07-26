//
//  이상한 문자 만들기.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/01.
//

// 시간복잡도: O(n)
// 최악시간: n
// 난이도: Level 1
// Timer: 15m
// Url: https://programmers.co.kr/skill_checks/466883?challenge_id=911

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int idx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            idx = 0;
            continue;
        }
        if(idx % 2 == 1) {
            if(s[i] <= 'Z') s[i] += 32;
        } else {
            if(s[i] >= 'a') s[i] -= 32;
        }
        idx++;
    }
    return s;
}
