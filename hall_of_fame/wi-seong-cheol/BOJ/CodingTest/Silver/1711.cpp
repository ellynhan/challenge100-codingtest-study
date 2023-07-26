//
//  1711.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/15.
//

/*
 [Input]
 5
 -1 1
 -1 0
 0 0
 1 0
 1 1
 [Output]
 7
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 2,250,000
// 난이도: Silver 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1711

#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;
typedef long long ll;
#define X first
#define Y second
int n;
ll ans;
vector<pair<ll, ll>> v;

void calc(int center){
    map<pair<ll, ll>, int> M;
    
    for(int i = 0; i < n; i++){
        if(i==center) continue;
        ll tx = v[i].X - v[center].X;
        ll ty = v[i].Y - v[center].Y;
        ll g = gcd(tx, ty);
        if(g < 0) g = -g;
        tx /= g;
        ty /= g;
        M[{tx, ty}]++;
    }
    for(auto elem : M){
        ll x = elem.X.X;
        ll y = elem.X.Y;
        if(M.find({-y, x}) != M.end())
            ans += elem.Y * M[{-y, x}];
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    for(int i = 0; i < n; i++) calc(i);
    cout << ans;
    
    return 0;
}
