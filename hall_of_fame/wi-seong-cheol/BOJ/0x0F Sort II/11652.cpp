//
//  11652.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/30.
//

/*
 [Input]
 5
 1
 2
 1
 2
 1
 [Output]
 1
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11652

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
int n;
ll arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    ll mxVal = arr[0];
    int mxCnt = 1;
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i - 1] == arr[i]) {
            cnt++;
        } else {
            if(mxCnt < cnt) {
                mxCnt = cnt;
                mxVal = arr[i - 1];
            }
            cnt = 1;
        }
    }
    if(mxCnt < cnt) mxVal = arr[n - 1];
    cout << mxVal;
    
    return 0;
}
