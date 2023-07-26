//
//  무지의 먹방 라이브.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/03.
//

// 시간복잡도: O(n)
// 최악시간: 200,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42891

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define time first
#define idx second

bool cmp(pair<ll, int>& a, pair<ll, int>& b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int n = food_times.size();
    vector<pair<ll, int>> food;
    
    for(int i = 0; i < n; i++)
        food.push_back({food_times[i], i + 1});
    sort(food.begin(), food.end());
    
    ll prev_time = 0;
    for(int i = 0; i < n; i++) {
        ll cnt = (ll)(n - i) * (food[i].time - prev_time);
        
        if(cnt == 0) continue;
        if(cnt <= k) {   // 모두 먹을 수 있을 때
            k -= cnt;
            prev_time = food[i].time;
        } else {         // 모두 먹을 수 없을 때
            k %= (n - i);
            sort(food.begin() + i, food.end(), cmp);
            return food[i + k].idx;
        }
    }
    
    return -1;
}
