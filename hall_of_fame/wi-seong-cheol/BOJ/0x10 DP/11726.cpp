//
//  11726.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 2
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11726

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[1001];
int mod = 10007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> n;
    d[0] = 1;
    d[1] = 2;
    for(int i = 2; i < n; i++)
        d[i] = (d[i - 1] + d[i - 2]) % mod;
    cout << d[n - 1];
    
    return 0;
}
