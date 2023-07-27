//
//  2491.cpp
//  main
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 9
 1 2 2 4 4 5 7 7 2
 [Output]
 8
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 4
// Timer: 15m
// Url: https://www.acmicpc.net/problem/2491

#include <iostream>
#include <algorithm>

using namespace std;
const int SIZE = 100'001;
int n;
int a[SIZE];
int down[SIZE];
int up[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    down[0] = up[0] = 1;
    for(int i = 1; i < n; i++) {
        down[i] = up[i] = 1;
        if(a[i - 1] <= a[i])
            down[i] += down[i - 1];
        if(a[i - 1] >= a[i])
            up[i] += up[i - 1];
    }
    cout << max(*max_element(down, down + n), *max_element(up, up + n));
            
    
    return 0;
}
