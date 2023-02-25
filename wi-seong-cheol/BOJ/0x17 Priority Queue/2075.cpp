//
//  2075.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 12 7 9 15 5
 13 8 11 19 6
 21 10 26 31 16
 48 14 28 35 25
 52 20 32 41 49
 [Output]
 35
 */
// 시간복잡도: O(nlogn)
// 최악시간: 5,000
// 난이도: Silver 2
// Timer: 3m
// Url: https://www.acmicpc.net/problem/2075

#include <iostream>
#include <queue>

using namespace std;
int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n*n; i++) {
        int x; cin >> x;
        if(pq.size() < n) {
            pq.push(x);
        } else {
            if(pq.top() < x) {
                pq.pop();
                pq.push(x);
            }
        }
    }
    cout << pq.top();
    
    return 0;
}
