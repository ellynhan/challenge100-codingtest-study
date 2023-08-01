//
//  1021.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

/*
 [Input]
 10 3
 1 2 3
 [Output]
 0
 */
// 시간복잡도: O(nlogn)
// 최악시간: 100
// 난이도: Silver 4
// Timer: 8m
// Url: https://www.acmicpc.net/problem/1021

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, ans;
deque<int> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        dq.push_back(i);
    
    while(m--) {
        int x; cin >> x;
        auto idx = find(dq.begin(), dq.end(), x) - dq.begin();
        while(x != dq.front()) {
            if(idx < dq.size() - idx) {
                dq.push_back(dq.front());
                dq.pop_front();
            } else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans++;
        }
        dq.pop_front();
    }
    cout << ans;
        
    
    return 0;
}
