//
//  2141.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/15.
//

/*
 [Input]
 3
 1 3
 2 5
 3 3
 [Output]
 2
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2141

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
#define X first
#define Y second
int n;
pair<int, int> a[100001];
ll sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].X >> a[i].Y;
        sum += a[i].Y;
    }
    sort(a, a + n);
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        cur += a[i].Y;
        if(cur >= (sum + 1) / 2) {
            cout << a[i].X;
            break;
        }
    }
        
    return 0;
}
