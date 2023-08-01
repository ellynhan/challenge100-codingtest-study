//
//  1927.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 9
 0
 12345678
 1
 2
 0
 0
 0
 0
 32
 [Output]
 0
 1
 2
 12345678
 0
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 2
// Timer: 2m
// Url: https://www.acmicpc.net/problem/1927

#include <iostream>
#include <queue>

using namespace std;
int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        int x; cin >> x;
        if(x == 0) {
            if(pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
    
    return 0;
}
