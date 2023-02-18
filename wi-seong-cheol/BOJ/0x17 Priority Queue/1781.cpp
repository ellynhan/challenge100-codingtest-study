//
//  1781.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7
 1 6
 1 7
 3 2
 3 1
 2 4
 2 5
 6 1
 [Output]
 15
 */
// 시간복잡도: O(nlogn)
// 최악시간: 1,000,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1781

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define X first
#define Y second
#define ll long long

class cmp {
public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if(a.X == b.X) {
            return a.Y < b.Y;
        }
        return a.X > b.X;
    }
};

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
priority_queue<int, vector<int>, greater<int>> pqAns;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        pq.push({a, b});
    }
    int time = 0;
    ll ans = 0;
    while(!pq.empty()) {
        if(time < pq.top().X) {
            time++;
            pqAns.push(pq.top().Y);
        } else {
            if(pqAns.top() < pq.top().Y) {
                pqAns.pop();
                pqAns.push(pq.top().Y);
            }
        }
        pq.pop();
    }
    while(!pqAns.empty()) {
        ans += pqAns.top();
        pqAns.pop();
    }
    cout << ans;
    
    return 0;
}
