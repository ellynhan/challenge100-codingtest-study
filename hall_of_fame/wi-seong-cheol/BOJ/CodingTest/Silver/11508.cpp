//
//  11508.cpp
//  main
//
//  Created by wi_seong on 2023/02/10.
//

/*
 [Input]
 2
 1
 2
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11508

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, x, ans;
vector<int> a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    while(!a.empty()) {
        int x1 = a.back(); a.pop_back();
        if(a.empty()) {
            ans += x1;
            break;
        }
        int x2 = a.back(); a.pop_back();
        if(a.empty()) {
            ans += x1 + x2;
            break;
        }
        a.pop_back();
        ans += x1 + x2;
    }
    cout << ans;
    
    return 0;
}
