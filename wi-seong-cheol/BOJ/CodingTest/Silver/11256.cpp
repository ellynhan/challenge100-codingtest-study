//
//  11256.cpp
//  main
//
//  Created by wi_seong on 2023/02/25.
//

/*
 [Input]
 1
 20 5
 3 4
 2 5
 1 8
 3 3
 2 5
 [Output]
 2
 */
// 시간복잡도: O(nlogn)
// 최악시간: 30,000
// 난이도: Silver 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11256

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t, j, n, w, h;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> j >> n;
        v.clear();
        int ans = 0;
        while(n--) {
            cin >> w >> h;
            v.push_back(w * h);
        }
        sort(v.begin(), v.end(), greater<>());
        for(int x: v) {
            j -= x;
            ans++;
            if(j <= 0) break;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
