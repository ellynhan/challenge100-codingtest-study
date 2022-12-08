//
//  11053.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 6
 10 20 10 30 20 50
 [Output]
 4
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11053

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        d[i] = 1;
    }
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(arr[i] > arr[j])
                d[i] = max(d[i], d[j] + 1);
    cout << *max_element(d, d + n);
    
    return 0;
}
