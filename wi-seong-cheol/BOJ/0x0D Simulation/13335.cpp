//
//  13335.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 4 2 10
 7 4 5 6
 [Output]
 8
 */
// 시간복잡도: O(n * m)
// 최악시간: 100,000
// 난이도: Silver 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/13335

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
int n, w, l, ans;
queue<int> truck;
queue<pair<int, int>> bridge;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> w >> l;
    for(int i = 0; i < n; i++) {
        int weight; cin >> weight;
        truck.push(weight);
    }
    
    int time = 0;
    int sum = 0;
    while(!truck.empty()) {
        if(!bridge.empty()) {
            auto element = bridge.front();
            if(time - element.X == w) {
                sum -= element.Y;
                bridge.pop();
            }
        }
        
        if(sum + truck.front() <= l) {
            sum += truck.front();
            bridge.push({time, truck.front()});
            truck.pop();
        }
        time++;
    }
    cout << time + w;
    
    return 0;
}
