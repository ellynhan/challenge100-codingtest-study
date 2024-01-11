//
//  PI.cpp
//  main
//
//  Created by wi_seong on 1/11/24.
//

/*
 [Input]
 5
 12341234
 11111222
 12122222
 22222222 
 12673939
 [Output]
 4
 2
 5
 2
 14
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: 하
// Timer: 1시간
// Url: https://www.acmicpc.net/problem/PI

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define INF 987654321
int t;
string s;
int length;
int cache[10001];

int calculate(int st, int length) {
    string sub = s.substr(st, length);

    // 모든 숫자가 같을 때
    for(int i = 1; i < length; i++) {
        if(sub[i] != sub[i - 1]) break;
        if(i == length - 1) return 1;
    }

    // 숫자가 1씩 단조 증가하거나 감소할 때
    bool isIncrease = sub[0] < sub[1];
    for(int i = 1; i < length; i++) {
        if(sub[i] == sub[i - 1]) break;
        if(isIncrease) {
            if(sub[i] - sub[i - 1] != 1) break;
        } else {
            if(sub[i - 1] - sub[i] != 1) break;
        }
        if(i == length - 1) return 2;
    }

    // 두 개의 숫자가 번갈아가며 나타날 때
    for(int i = 2; i < length; i++) {
        if(sub[i] != sub[i - 2]) break;
        if(i == length - 1) return 4;
    }

    // 숫자가 등차 수열을 이룰 때
    int diff = sub[1] - sub[0];
    for(int i = 1; i < length; i++) {
        if(sub[i] - sub[i - 1] != diff) break;
        if(i == length - 1) return 5;
    }

    return 10;
}

int solve(int st) {
    if(st == length) return 0;
    int &ret = cache[st];
    if(ret != -1) return ret;

    ret = INF;
    for(int len = 3; len <= 5; len++) {
        if(st + len > length) continue;
        ret = min(ret, calculate(st, len) + solve(st + len));
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        cin >> s;
        length = int(s.length());
        cout << solve(0) << '\n';
    }

	return 0;
}
