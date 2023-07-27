//
//  2143.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 4
 1 3 1 2
 3
 1 3 2
 [Output]
 7
 */
// 시간복잡도: O(n^2)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 40m
// Url: https://www.acmicpc.net/problem/2143

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
ll ans;
int t, n, m;
vector<int> a;
vector<int> sumA;
vector<int> b;
vector<int> sumB;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        b.push_back(x);
    }
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += a[j];
            sumA.push_back(sum);
        }
    }
    for(int i = 0; i < m; i++) {
        int sum = 0;
        for(int j = i; j < m; j++) {
            sum += b[j];
            sumB.push_back(sum);
        }
    }
    sort(sumB.begin(), sumB.end());
    for(int i = 0; i < sumA.size(); i++) {
        int f = t - sumA[i];
        auto up = upper_bound(sumB.begin(), sumB.end(), f);
        auto lp = lower_bound(sumB.begin(), sumB.end(), f);
        ans += up - lp;
    }
    cout << ans;
    
    return 0;
}
