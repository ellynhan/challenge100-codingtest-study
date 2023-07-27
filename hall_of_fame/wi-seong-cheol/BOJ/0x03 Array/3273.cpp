//
//  3273.cpp
//  main
//
//  Created by wi_seong on 2022/11/06.
//

/*
 [Input]
 9
 5 12 7 10 9 1 2 3 11
 13
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 1000000
// 난이도: Silver 3
// Timer: 5m
// Url: https://www.acmicpc.net/problem/3273

#include <iostream>

using namespace std;
int n, x;
int arr[2000001];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        arr[a] = 1;
    }
    cin >> x;
    for(int i = 1; i < (x + 1)/2; i++)
        if(arr[i] && arr[x - i]) ans++;
    cout << ans;
    
    return 0;
}
