//
//  10814.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/25.
//

/*
 [Input]
 3
 21 Junkyu
 21 Dohyun
 20 Sunyoung
 [Output]
 20 Sunyoung
 21 Junkyu
 21 Dohyun
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 5
// Timer: 12m
// Url: https://www.acmicpc.net/problem/10814

#include <iostream>
#include <vector>

using namespace std;
#define X first
#define Y second
int n, age;
string name;
vector<pair<int, string>> v;
vector<pair<int, string>> tmp(100001);

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int lidx = st;
    int ridx = mid;
    for(int i = st; i < en; i++) {
        if(ridx == en) tmp[i] = v[lidx++];
        else if(lidx == mid) tmp[i] = v[ridx++];
        else if(v[lidx].X <= v[ridx].X) tmp[i] = v[lidx++];
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
        cin >> age >> name;
        v.push_back({age, name});
    }
    merge_sort(0, n);
    for(auto element: v)
        cout << element.X << ' ' << element.Y << '\n';
    
    return 0;
}
