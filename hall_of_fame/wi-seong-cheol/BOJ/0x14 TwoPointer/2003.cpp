//
//  2003.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 10 5
 1 2 3 4 2 5 3 1 1 2
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2003

#include <iostream>

using namespace std;
int n, m;
int en, sum, cnt;
int a[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int st = 0; st < n; st++) {
        while(en < n && sum < m) {
            sum += a[en++];
        }
        
        if(sum == m) cnt++;
        sum -= a[st];
    }
    cout << cnt;
    
    return 0;
}
