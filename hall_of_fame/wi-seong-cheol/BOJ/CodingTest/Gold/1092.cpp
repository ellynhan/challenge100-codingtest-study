//
//  1092.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/15.
//

/*
 [Input]
 10
 11 17 5 2 20 7 5 5 20 7
 5
 18 18 15 15 17
 [Output]
 2
 */
// 시간복잡도: O(n^2)
// 최악시간: 500,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1092

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, x, t;
vector<int> a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end());
    if(a.front() < b.back()) {
        cout << -1;
        return 0;
    }
    
    while(!b.empty()) {
        t++;
        for(int w: a) {
            if(b.empty()) break;
            for(int i = (int)b.size() - 1; i >= 0; i--) {
                if(w < b[i]) continue;
                b.erase(b.begin() + i);
                break;
            }
        }
    }
    cout << t;
    
    return 0;
}
