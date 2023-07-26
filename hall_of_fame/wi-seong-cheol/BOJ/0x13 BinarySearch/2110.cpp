//
//  2110.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 3
 1
 2
 8
 4
 9
 [Output]
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 1,000,000
// 난이도: Gold
// Timer: 40m
// Url: https://www.acmicpc.net/problem/2110

#include <iostream>
#include <algorithm>

using namespace std;
int n, c;
int a[200002];

bool solve(int len){
    int idx = 0, cnt = 0;
    while(idx != n) {
        idx = (int)(lower_bound(a + idx, a + n, a[idx] + len) - a);
        cnt++;
    }
    return cnt >= c;
}

int binarySearch() {
    int st = 1, en = 1000000000;
    
    while(st < en) {
        int mid = (st + en + 1) / 2;
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }
    
    return st;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> c;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cout << binarySearch();
    
    return 0;
}
