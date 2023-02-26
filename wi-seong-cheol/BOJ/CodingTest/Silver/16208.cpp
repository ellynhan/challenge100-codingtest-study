//
//  16208.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/24.
//

/*
 [Input]
 4
 3 5 4 2
 [Output]
 71
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Silver 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/16208

#include <iostream>

using namespace std;
#define ll long long
int n, a[500001];
ll sum, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0) continue;
        sum += a[i - 1];
        ans += sum * a[i];
    }
    cout << ans;
    
    return 0;
}
