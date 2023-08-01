//
//  20300.cpp
//  main
//
//  Created by wi_seong on 2023/02/11.
//

/*
 [Input]
 5
 1 2 3 4 5
 [Output]
 5
 */
// 시간복잡도: O(nlogn)
// 최악시간: 40,000
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/20300

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long
int n;
ll ans, x;
vector<ll> a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    if(a.size() % 2 == 1) {
        ans = a.back();
        a.pop_back();
    }
    for(int i = 0; i < a.size() / 2; i++)
        ans = max(ans, a[i] + a[a.size() - i - 1]);
    cout << ans;
    
    return 0;
}
