//
//  11286.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 18
 1
 -1
 0
 0
 0
 1
 1
 -1
 -1
 2
 -2
 0
 0
 0
 0
 0
 0
 0
 [Output]
 -1
 1
 0
 -1
 -1
 1
 1
 -2
 2
 0
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11286

#include <iostream>
#include <queue>

using namespace std;
int n;

class cmp {
public:
    bool operator() (int a, int b) {
        if(abs(a) != abs(b)) return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int>, cmp> pq;
    cin >> n;
    while(n--) {
        int x; cin >> x;
        if(x != 0) {
            pq.push(x);
        } else {
            if(pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
    
    return 0;
}
