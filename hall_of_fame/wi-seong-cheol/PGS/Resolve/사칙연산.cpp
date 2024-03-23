//
//  사칙연산.cpp
//  main
//
//  Created by wi_seong on 3/19/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 20,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1843

#include <vector>
#include <string>
#include <cstring>

using namespace std;
const int INF = 1e9 + 7;
int answer;
int cache[2][101][101];
vector<int> number;
vector<string> op;
vector<string> arr;

int solve(int k, int st, int en) {
    if(st == en) return number[st];
    int& ret = cache[k][st][en];
    if(ret != -1) return ret;

    ret = k ? -INF : INF;
    for(int i = st; i < en; i++) {
        if(op[i] == "-") {
            if(k) {
                ret = max(ret, solve(true, st, i) - solve(false, i + 1, en));
            } else {
                ret = min(ret, solve(false, st, i) - solve(true, i + 1, en));
            }
        } else {
            if(k) {
                ret = max(ret, solve(true, st, i) + solve(true, i + 1, en));
            } else {
                ret = min(ret, solve(false, st, i) + solve(false, i + 1, en));
            }
        }
    }

    return ret;
}

int solution(vector<string> _arr) {
    arr = _arr;
    int n = int(arr.size());
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            number.push_back(stoi(arr[i]));
        } else {
            op.push_back(arr[i]);
        }
    }
    memset(cache, -1, sizeof(cache));
    answer = solve(true, 0, n / 2);

    return answer;
}
