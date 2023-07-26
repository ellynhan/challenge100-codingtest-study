//
//  14002.cpp
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
 10 20 30 50
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14002

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, idx, mx;
int arr[1001];
int d[1001];
int p[1001];
deque<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    fill(d, d + n, 1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(arr[i] > arr[j]) {
                if(d[i] < d[j] + 1) {
                    d[i] = d[j] + 1;
                    p[i] = j;
                }
            }
        }
    }
    mx = d[1]; idx = 1;
    for(int i = 2; i <= n; i++) {
        if(mx < d[i]) {
            mx = d[i];
            idx = i;
        }
    }
    while(idx) {
        v.push_front(arr[idx]);
        idx = p[idx];
    }
    cout << v.size() << '\n';
    for(auto x: v)
        cout << x << ' ';
    
    return 0;
}
