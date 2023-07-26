//
//  다리를 지나는 트럭.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Level 2
// Timer: 32m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>

using namespace std;
#define X first
#define Y second

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    queue<pair<int, int>> bridge;
    int time, cur = 0;
        
    for(size_t i = 0; i < truck_weights.size(); i++) {
        time++;
        if(time == bridge.front().Y + bridge_length) {
            cur -= bridge.front().X;
            bridge.pop();
        }
        while(weight < cur + truck_weights[i]) {
            time = bridge.front().Y + bridge_length;
            cur -= bridge.front().X;
            bridge.pop();
        }
        cur += truck_weights[i];
        bridge.emplace(truck_weights[i], time);
    }
    
    return time;
}
