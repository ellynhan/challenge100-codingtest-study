//
//  10816.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 10
 6 3 2 10 10 10 -10 -10 7 3
 8
 10 9 -5 2 3 4 5 -10
 [Output]
 3 0 0 1 2 0 0 2
 */
// 시간복잡도: O(logn)
// 최악시간: 20
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/10816

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int a[500001];

int lower_idx(int target) {
    int st = 0;
    int en = n;
    int idx = 0;
    while(st < en) {
        int mid = (st + en) / 2;
        if(a[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int target) {
    int st = 0;
    int en = n;
    int idx = 0;
    while(st < en) {
        int mid = (st + en) / 2;
        if(a[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cin >> m;
    while(m--) {
        int x; cin >> x;
        cout << upper_idx(x) - lower_idx(x) << ' ';
    }
    
    return 0;
}
