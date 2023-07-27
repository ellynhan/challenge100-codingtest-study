//
//  .cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 3
 5
 5
 5
 [Output]
 3
 */
// 시간복잡도: O(n^2)
// 최악시간: 10,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2847

#include <iostream>

using namespace std;
int n, ans;
int a[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] <= a[i - 1]) {
            for(int j = i - 1; j > 0; j--) {
                if(a[j] < a[j + 1]) break;
                ans += a[j] - a[j + 1] + 1;
                a[j] = a[j + 1] - 1;
            }
        }
    }
    cout << ans;
    
    return 0;
}
