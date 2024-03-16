//
//  14469.cpp
//  main
//
//  Created by wi_seong on 3/12/24.
//

/*
 [Input]
 3
 2 1
 8 3
 5 7
 [Output]
 15
 */
// 시간복잡도: O(nlogn)
// 최악시간: 200
// 난이도: Silver 4
// Timer: 3m
// Url: https://www.acmicpc.net/problem/14469

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int>> cow;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cow.push_back({a, b});
    }
    sort(cow.begin(), cow.end());
    int time = 0;
    for(auto c: cow) {
        if(time < c.first) time = c.first;
        time += c.second;
    }
    cout << time;

    return 0;
}
