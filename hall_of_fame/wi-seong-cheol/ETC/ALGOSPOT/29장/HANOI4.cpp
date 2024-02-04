//
//  HANOI4.cpp
//  main
//
//  Created by wi_seong on 1/27/24.
//

/*
 [Input]
 3
 5
 1 1
 1 3
 2 5 4
 1 2
 3
 1 2
 0
 2 3 1
 0
 10
 2 8 7
 2 5 4
 3 6 3 2
 3 10 9 1
 [Output]
 10
 4
 24
 */
// 시간복잡도: O(P ^ (n + 2))
// 최악시간: 25,000,000
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/HANOI4

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAX_DISKS = 12;
int t, n, disks;
int c[1 << (MAX_DISKS * 2)];

int get(int state, int index) {
    return (state >> (index * 2)) & 3;
}

int set(int state, int index, int value) {
    return (state & ~(3 << (index * 2))) | (value << (index * 2));
}

int sgn(int x) {
    if(!x) {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

int incr(int x) {
    if(x < 0) {
        return x - 1;
    }
    return x + 1;
}

int solve(int n, int begin, int end) {
    if(begin == end) {
        return 0;
    }
    queue<int> Q;
    memset(c, 0, sizeof(c));
    Q.push(begin);
    c[begin] = 1;
    Q.push(end);
    c[end] = -1;
    while(!Q.empty()) {
        int here = Q.front();
        Q.pop();
        int top[4] = {-1, -1, -1, -1};
        for(int i = n - 1; i >= 0; i--) {
            top[get(here, i)] = i;
        }
        for(int i = 0; i < 4; i++) {
            if(top[i] != -1) {
                for(int j = 0; j < 4; j++) {
                    if(i != j && (top[j] == -1 || top[j] > top[i])) {
                        int there = set(here, top[i], j);
                        if(c[there] == 0) {
                            c[there] = incr(c[here]);
                            Q.push(there);
                        } else if(sgn(c[there]) != sgn(c[here])) {
                            return abs(c[there]) + abs(c[here]) - 1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        int begin = 0;
        int end = 0;
        cin >> disks;
        for(int i = 0; i < 4; i++) {
            cin >> n;
            for(int j = 0; j < n; j++) {
                int disk;
                cin >> disk;
                begin = set(begin, disk - 1, i);
            }
        }
        for(int i = 0; i < disks; i++) {
            end = set(end, i, 3);
        }
        cout << solve(disks, begin, end) << '\n';
    }

	return 0;
}
