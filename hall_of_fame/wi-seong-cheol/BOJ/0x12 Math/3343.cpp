//
//  3343.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 22 2 3 10 14
 [Output]
 31
 */
// 시간복잡도: O(logn)
// 최악시간: 15
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/3343

#include <iostream>
#include <numeric>

using namespace std;
#define ll long long
ll target, a_unit, a_cost, b_unit, b_cost;

ll solve(ll a_unit, ll a_cost, ll b_unit, ll b_cost, ll target) {
    ll minimum_amount = 1e18 + 1;
    ll lcmAB = lcm(a_unit, b_unit);
    int a_bundle = 0;
    
    while(a_unit * a_bundle < lcmAB) {
        if(target <= a_unit * a_bundle) {
            if(a_cost * a_bundle < minimum_amount)
                minimum_amount = a_cost * a_bundle;
            break;
        }
        ll remainder = target - a_unit * a_bundle;
        ll b_bundle = (remainder - 1) / b_unit + 1;
        ll cost = a_cost * a_bundle + b_cost * b_bundle;
        if(cost < minimum_amount)
            minimum_amount = cost;
        a_bundle++;
    }
    
    return minimum_amount;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> target >> a_unit >> a_cost >> b_unit >> b_cost;
    
    if(b_cost * a_unit < a_cost * b_unit)
        cout << solve(a_unit, a_cost, b_unit, b_cost, target);
    else
        cout << solve(b_unit, b_cost, a_unit, a_cost, target);
    
    return 0;
}
