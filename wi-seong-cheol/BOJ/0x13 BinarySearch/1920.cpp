//
//  1920.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 4 1 5 2 3
 5
 1 3 7 9 5
 [Output]
 1
 1
 0
 0
 1
 */
// 시간복잡도: O(logn)
// 최악시간: 4
// 난이도: Silver 4
// Timer: 5m
// Url: https://www.acmicpc.net/problem/1920

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int arr[100001];

int binarySearch(int x) {
    int st = 0;
    int en = n - 1;
    while(st <= en) {
        int mid = (st + en) / 2;
        if(arr[mid] == x) {
            return 1;
        } else if(arr[mid] > x) {
            en = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cin >> m;
    for(int j = 0; j < m; j++) {
        int x; cin >> x;
        cout << binarySearch(x) << '\n';
    }
    
    return 0;
}
