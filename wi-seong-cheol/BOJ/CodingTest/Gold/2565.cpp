//
//  2565.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/15.
//

/*
 [Input]
 8
 1 8
 3 9
 2 2
 4 1
 6 4
 10 10
 9 7
 7 6
 [Output]
 3
 */
// 시간복잡도: O(n^2)
// 최악시간: 10,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2565

#include <iostream>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n;
pair<int, int> a[101];
int d[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;
    sort(a, a + n);
    d[0] = 1;
    for(int i = 1; i < n; i++) {
        int m = 0;
        for(int j = 0; j < i; j++)
            if(a[j].Y < a[i].Y)
                m = max(m, d[j]);
        d[i] = m + 1;
    }
    cout << n - *max_element(d, d + n);
    
    return 0;
}
