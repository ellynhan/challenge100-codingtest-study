//
//  14891.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 10101111
 01111101
 11001110
 00000010
 2
 3 -1
 1 1
 [Output]
 7
 */
// 시간복잡도: O(k * n * m)
// 최악시간: 384
// 난이도: Gold 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/14891

#include <iostream>
#include <deque>
#include <cmath>
#include <queue>

using namespace std;
deque<int> board[4];

void rotate(int idx, int dir) {
    if(dir == 1) {
        board[idx].push_front(board[idx].back());
        board[idx].pop_back();
    } else {
        board[idx].push_back(board[idx].front());
        board[idx].pop_front();
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    for(int i = 0; i < 4; i++) {
        string s; cin >> s;
        for(int j = 0; j < 8; j++) {
            if(s[j] == '0') board[i].push_back(0);
            else board[i].push_back(1);
        }
    }

    int t; cin >> t;
    while(t--) {
        int k, dir;
        cin >> k >> dir;
        int d[4] = {0, };
        d[--k] = dir;
        queue<int> Q;
        Q.push(k);

        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            int left = cur - 1;
            int right = cur + 1;
            if(left >= 0 && d[left] == 0) {
                if(board[cur][6] != board[left][2]) {
                    d[left] = d[cur] * -1;
                    Q.push(left);
                }
            }
            if(right < 4 && d[right] == 0) {
                if(board[cur][2] != board[right][6]) {
                    d[right] = d[cur] * -1;
                    Q.push(right);
                }
            }
        }

        for(int i = 0; i < 4; i++) {
            if(d[i] != 0) rotate(i, d[i]);
        }
    }

    int answer = 0;
    for(int i = 0; i < 4; i++) {
        if(board[i][0] == 1)
            answer += pow(2, i);
    }
    cout << answer;

	return 0;
}
