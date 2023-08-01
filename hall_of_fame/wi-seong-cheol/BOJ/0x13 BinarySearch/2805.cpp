//
//  2805.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 7
 20 15 10 17
 [Output]
 15
 */
// 시간복잡도: O(nlogh)
// 최악시간: 9,000,000
// 난이도: Silver 2
// Timer: 40m
// Url: https://www.acmicpc.net/problem/2805

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long
int n, m;
vector<int> tree;

bool solve(int h) {
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        if(tree[i] <= h) continue;
        sum += tree[i] - h;
    }
    return sum >= m;
}

int binarySearch() {
    int st = 0;
    int en = *max_element(tree.begin(), tree.end());
    
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
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int len; cin >> len;
        tree.push_back(len);
    }
    cout << binarySearch();
    
    return 0;
}
