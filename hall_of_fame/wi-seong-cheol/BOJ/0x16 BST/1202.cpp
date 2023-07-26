//
//  1202.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 2 1
 5 10
 100 100
 11
 [Output]
 10
 */
// 시간복잡도: O(n)
// 최악시간: 300,000
// 난이도: Gold 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1202

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define X first
#define Y second
#define ll long long
int n, k, m, v;
pair<int, int> jewel[300001];
multiset<int> bag;
ll ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> jewel[i].Y >> jewel[i].X;
    sort(jewel, jewel + n);
    
    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        bag.insert(x);
    }
    
    for(int i = n - 1; i >= 0; i--) {
        tie(v, m) = jewel[i];
        auto it = bag.lower_bound(m);
        if(it == bag.end()) continue;
        ans += v;
        bag.erase(it);
    }
    cout << ans;
    
    return 0;
}
