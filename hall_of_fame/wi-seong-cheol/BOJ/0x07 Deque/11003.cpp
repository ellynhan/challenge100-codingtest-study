//
//  11003.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

/*
 [Input]
 12 3
 1 5 2 3 6 2 3 7 3 5 2 6
 [Output]
 1 1 1 2 2 2 2 2 3 3 2 2
 */
// 시간복잡도: O()
// 최악시간: 
// 난이도: Gold 1
// Timer: 16m
// Url: https://www.acmicpc.net/problem/11003

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
int N, L;
deque<pair<int, int>> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> L;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        if(!dq.empty() && i - dq.front().Y == L)
            dq.pop_front();
        while(!dq.empty() && dq.back().X > x)
            dq.pop_back();
        dq.push_back(make_pair(x, i));
        cout << dq.front().X << ' ';
    }
    
    return 0;
}
