//
//  .cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 5
 5 2 4 1 3
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 12m
// Url: https://www.acmicpc.net/problem/7570

#include <iostream>
#include <algorithm>

using namespace std;
int n, ans;
int d[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        d[x] = d[x - 1] + 1;
        ans = max(ans, d[x]);
    }
    cout << n - ans;
    
    return 0;
}
