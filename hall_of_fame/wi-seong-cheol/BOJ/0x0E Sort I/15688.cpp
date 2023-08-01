//
//  15688.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/25.
//

/*
 [Input]
 5
 5
 4
 3
 2
 1
 [Output]
 1
 2
 3
 4
 5
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Silver 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/15688

#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> v;
vector<int> tmp(1000001);

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int lidx = st;
    int ridx = mid;
    for(int i = st; i < en; i++) {
        if(ridx == en) tmp[i] = v[lidx++];
        else if(lidx == mid) tmp[i] = v[ridx++];
        else if(v[lidx] <= v[ridx]) tmp[i] = v[lidx++];
        else tmp[i] = v[ridx++];
    }
    for(int i = st; i < en; i++)
        v[i] = tmp[i];
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
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    merge_sort(0, n);
    for(auto x: v)
        cout << x << '\n';
    
    return 0;
}
