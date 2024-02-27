//
//  지형 편집.cpp
//  main
//
//  Created by wi_seong on 2/6/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 90,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12984

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
typedef long long ll;
int n;

ll solution(vector<vector<int>> land, int P, int Q) {
    vector<int> v;
    ll total = 0;

    for(int i = 0; i < int(land.size()); i++) {
        for(int j = 0; j < int(land[0].size()); j++) {
            v.push_back(land[i][j]);
            total += ll(land[i][j]);
        }
    }
    n = int(v.size());
    sort(v.begin(), v.end());

    ll subNum = ll(v[0]) * n;
    ll curCost = (total - subNum) * ll(Q);
    ll answer = curCost;

    for(int i = 1; i < n; i++) {
        if(v[i] == v[i - 1]) continue;

        ll addFloor = ll(v[i] - v[i - 1]);

        curCost -= addFloor * (n - i) * Q;
        curCost += addFloor * i * P;

        if(answer < curCost) break;
        answer = curCost;
    }

    return answer;
}
