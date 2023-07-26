//
//  11931.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/25.
//

/*
 [Input]
 5
 1
 2
 3
 4
 5
 [Output]
 5
 4
 3
 2
 1
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Silver 5
// Timer: 5m
// Url: https://www.acmicpc.net/problem/11931

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1000001;
int n;
int arr[SIZE];
int tmp[SIZE];

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int lidx = st;
    int ridx = mid;
    for(int i = st; i < en; i++) {
        if(ridx == en) tmp[i] = arr[lidx++];
        else if(lidx == mid) tmp[i] = arr[ridx++];
        else if(arr[lidx] >= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for(int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
    if(en == st + 1) return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(0, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << '\n';
    
    return 0;
}
