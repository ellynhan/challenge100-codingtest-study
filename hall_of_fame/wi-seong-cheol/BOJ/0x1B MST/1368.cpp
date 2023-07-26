//
//  1368.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4
 5
 4
 4
 3
 0 2 2 2
 2 0 3 3
 2 3 0 4
 2 3 4 0
 [Output]
 9
 */
// 시간복잡도: O(ElogE)
// 최악시간: 500,000
// 난이도: Gold 2
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1368

#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;
int v, e;
tuple<int,int,int> edge[100001];
vector<int> p(301,-1);

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(p[a] == p[b]) p[a]--;
    if(p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v;
    for(int i = 1; i <= v; i++) {
        int cost; cin >> cost;
        edge[e++] = {cost, i, v + 1};
    }
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            int cost; cin >> cost;
            if(i >= j) continue;
            edge[e++] = {cost, i, j};
        }
    }
    v++; // 가상의 정점까지 포함해야 하므로 정점 수를 1 증가시킴
    sort(edge, edge + e);
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        if(cnt == v - 1) break;
    }
    cout << ans;
    
    return 0;
}
