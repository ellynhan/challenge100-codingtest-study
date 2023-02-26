//
//  2792.cpp
//  main
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 7 5
 7
 1
 7
 4
 4
 [Output]
 4
 */
// 시간복잡도: O(mlogn)
// 최악시간: 2,700,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2792

#include <iostream>

using namespace std;
int n, m, a[300'001], ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> a[i];
    
    int st = 1, en = 1000000001;
    while(st <= en) {
        int mid = (st + en) / 2;
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            cnt += a[i] / mid;
            if(a[i] % mid != 0)
                cnt++;
        }
        if(cnt <= n) {
            ans = mid;
            en = mid - 1;
        }
        else st = mid + 1;
    }
    cout << ans;
    
    return 0;
}

/*
 300'000'000'000'000
 5 1
 5
 */
