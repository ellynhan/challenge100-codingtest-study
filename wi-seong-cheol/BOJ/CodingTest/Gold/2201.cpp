//
//  2201.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/03.
//

/*
 [Input]
 7
 [Output]
 1010
 */
// 시간복잡도: O(n)
// 최악시간: 200
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2201

#include <iostream>

using namespace std;
#define ll long long
ll n;
ll a[201];
int len;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    if(n == 1) {
        cout << 1;
        return 0;
    }
    if(n == 2) {
        cout << 10;
        return 0;
    }
    a[0] = 1; a[1] = 2; a[2] = 3;
    len = 2;
    while(1) {
        a[len] = a[len - 1] + a[len - 2];
        if(a[len] > n) break;
        len++;
    }
    int digit = len - 1;
    while(digit >= 0) {
        if(a[digit] <= n) {
            cout << 1;
            n -= a[digit];
            digit--;
        } else {
            cout << 0;
            digit--;
        }
    }
    
    return 0;
}
