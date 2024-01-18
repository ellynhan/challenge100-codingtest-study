//
//  CLOCKSYNC.cpp
//  main
//
//  Created by wi_seong on 1/12/24.
//

/*
 [Input]
 2
 12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
 12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
 [Output]
 2
 9
 */
// 시간복잡도: O(4 ^ n)
// 최악시간: 1,048,576
// 난이도: 중
// Timer: 40m
// Url: https://algospot.com/judge/problem/read/CLOCKSYNC

#include <iostream>

using namespace std;
#define INF 987654321
int t;
int ck[16];
int op[10][5] = {
    { 0, 1, 2, -1 },
    { 3, 7, 9, 11, -1 },
    { 4, 10, 14, 15, -1 },
    { 0, 4, 5, 6, 7 },
    { 6, 7, 8, 10, 12 },
    { 0, 2, 14, 15, -1 },
    { 3, 14, 15, -1 },
    { 4, 5, 7, 14, 15 },
    { 1, 2, 3, 4, 5 },
    { 3, 4, 5, 9, 13 }
};

void push(int order) {
    for(int idx: op[order]) {
        if(idx == -1) break;
        ck[idx] += 3;
    }
}

bool isCheck() {
    for(int i = 0; i < 16; i++)
        if(ck[i] % 4 != 0)
            return false;
    return true;
}

int solve(int cnt) {
    if(cnt == 10) return isCheck() ? 0 : INF;

    int ret = INF;
    for(int order = 0; order < 4; order++) {
        ret = min(ret, solve(cnt + 1) + order);
        push(cnt);
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        for(int i = 0; i < 16; i++)
            cin >> ck[i];
        int ret = solve(0);
        cout << (ret == INF ? -1 : ret) << '\n';
    }

	return 0;
}
