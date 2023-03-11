//
//  17521.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/16.
//

/*
 [Input]
 7 54
 7
 5
 5
 4
 2
 2
 1
 [Output]
 54
 */
// 시간복잡도: O(n)
// 최악시간: 15
// 난이도: Silver 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/17521

#include <iostream>

using namespace std;
#define ll long long
int n;
ll coin, w, a[16];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> w;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        if(w >= a[i] && a[i] < a[i + 1]) {
            coin += w / a[i];
            w = w % a[i];
        } else if(a[i] > a[i + 1]) {
            w += coin * a[i];
            coin = 0;
        }
    }
    w += coin * a[n - 1];
    cout << w;
    
    return 0;
}
