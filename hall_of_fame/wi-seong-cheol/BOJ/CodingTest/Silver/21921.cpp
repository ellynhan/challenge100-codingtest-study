//
//  21921.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/06.
//

/*
 [Input]
 7 5
 1 1 1 1 1 5 1
 [Output]
 9
 2
 */
// 시간복잡도: O(n)
// 최악시간: 250,000
// 난이도: Silver 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/21921

#include <iostream>
#include <algorithm>

using namespace std;
int ans;
int n, m;
int a[250001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int en = 0;
    int sum = 0;
    int cnt = 0;
    for(int st = 0; st <= n - m; st++) {
        while(en - st != m) {
            sum += a[en++];
        }
        if(ans < sum) {
            cnt = 1;
            ans = sum;
        } else if(ans == sum) {
            cnt++;
        }
        sum -= a[st];
    }
    if(ans == 0) cout << "SAD";
    else cout << ans << '\n' << cnt;
    
    return 0;
}
