//
//  1965.cpp
//  main
//
//  Created by wi_seong on 2023/02/10.
//

/*
 [Input]
 10
 1 2 3 4 5 6 7 8 9 10
 [Output]
 10
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Silver 2
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1965

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] = 1;
    }
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] < a[j])
                d[j] = max(d[j], d[i] + 1);
    cout << *max_element(d, d + n);
    
    return 0;
}
