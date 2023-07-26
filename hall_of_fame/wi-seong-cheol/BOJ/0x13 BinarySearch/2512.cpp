//
//  2512.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4
 120 110 140 150
 485
 [Output]
 127
 */
// 시간복잡도: O(nlog(n^2))
// 최악시간: 80,000
// 난이도: Silver 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2512

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, ans;
int a[10001];

int sumPrice(int x) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > x) sum += x;
        else sum += a[i];
    }
    return sum;
}

void binarySearch() {
    int st = 0;
    int en = a[n - 1];
    while(st <= en) {
        int mid = (st + en) / 2;
        int sum = sumPrice(mid);
        if(sum == m) {
            ans = mid;
            return;
        } else if(sum > m) {
            en = mid - 1;
        } else {
            ans = max(ans, mid);
            st = mid + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    sort(a, a + n);
    binarySearch();
    cout << ans;
    
    return 0;
}
