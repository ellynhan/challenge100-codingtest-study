//
//  11279.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 13
 0
 1
 2
 0
 0
 3
 2
 1
 0
 0
 0
 0
 0
 [Output]
 0
 2
 1
 3
 2
 1
 0
 0
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: 2m
// Timer: Silver 2
// Url: https://www.acmicpc.net/problem/11279

#include <iostream>
#include <queue>

using namespace std;
int n;
priority_queue<int> pq;

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
