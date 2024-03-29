//
//  불량 사용자.cpp
//  main
//
//  Created by wi_seong on 3/21/24.
//

// 시간복잡도: O(2 ^ n)
// 최악시간: 256
// 난이도: Level 3
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/64064

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
int n, m;
unordered_set<int> s;
vector<string> user_id, banned_id;

bool isBanned(const string& a, const string& b) {
    int len1 = int(a.length());
    int len2 = int(b.length());
    if(len1 == len2) {
        for(int i = 0; i < len1; i++) {
            if(a[i] == b[i]) continue;
            if(a[i] == '*' || b[i] == '*') continue;
            return false;
        }
        return true;
    }
    return false;
}

void solve(int k, int used) {
    if(k == n) {
        s.insert(used);
        return;
    }

    for(int i = 0; i < m; i++) {
        if(used & (1 << i)) continue;
        if(!isBanned(user_id[i], banned_id[k])) continue;
        used |= (1 << i);
        solve(k + 1, used);
        used -= (1 << i);
    }
}

int solution(vector<string> _user_id, vector<string> _banned_id) {
    user_id = _user_id;
    banned_id = _banned_id;
    n = int(banned_id.size());
    m = int(user_id.size());
    solve(0, 0);
    int answer = int(s.size());

    return answer;
}
