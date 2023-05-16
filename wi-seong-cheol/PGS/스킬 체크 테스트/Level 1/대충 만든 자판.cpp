//
//  대충 만든 자판.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/01.
//

// 시간복잡도: O(n * m)
// 최악시간: 3,200
// 난이도: Level 1
// Timer: 10m
// Url: https://programmers.co.kr/skill_checks/466883?challenge_id=16705

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;
int d[32];

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    fill(d, d + 32, INF);
    for(string key: keymap) {
        for(int i = 0; i < key.size(); i++)
            d[key[i] - 'A'] = min(xqd[key[i] - 'A'], i + 1);
    }
    for(string target: targets) {
        int cnt = 0;
        for(int i = 0; i < target.size(); i++) {
            if(d[target[i] - 'A'] == INF) {
                cnt = -1;
                break;
            }
            cnt += d[target[i] - 'A'];
        }
        answer.push_back(cnt);
    }
    
    return answer;
}
