//
//  9613.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 3
 4 10 20 30 40
 3 7 5 12
 3 125 15 25
 [Output]
 70
 3
 35
 */
// 시간복잡도: O((n^2)logN)
// 최악시간: 20,000
// 난이도: Silver 4
// Timer: 15m
// Url: https://www.acmicpc.net/problem/9613

#include <iostream>

using namespace std;
#define ll long long
int t, n;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> n;
        int a[n];
        ll sum = 0;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        for(int i = 0; i < n - 1; i++)
            for(int j = i + 1; j < n; j++)
                sum += gcd(a[i], a[j]);
        cout << sum << '\n';
    }
    
    return 0;
}
