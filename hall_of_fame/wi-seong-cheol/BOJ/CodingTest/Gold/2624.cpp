//
//  2624.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/10.
//

/*
 [Input]
 20
 3
 5 3
 10 2
 1 5
 [Output]
 4
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2624

#include <iostream>

using namespace std;
int T, K;
int p[10001];
int cnt[10001];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T >> K;
    for(int i = 0; i < K; i++)
        cin >> p[i] >> cnt[i];
    d[0] = 1;
    for(int i = 0; i < K; i++) {
        for(int j = T; j >= 1; j--) {
            int sum = 0;
            for(int k = 0; k < cnt[i]; k++) {
                sum += p[i];
                if (j - sum >= 0 && d[j - sum] > 0) d[j] += d[j - sum];
            }
        }
    }
    cout << d[T];
    
    return 0;
}
