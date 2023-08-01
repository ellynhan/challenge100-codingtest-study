//
//  16401.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3 10
 1 2 3 4 5 6 7 8 9 10
 [Output]
 8
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Silver 2
// Timer: 40m
// Url: https://www.acmicpc.net/problem/16401

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long
int n, m;
vector<int> a;

int solve(int x) {
    if(x == 0) return true;
    ll cnt = 0;
    for(int val: a)
        cnt += val / x;
    return cnt >= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    int st = 0;
    int en = *max_element(a.begin(), a.end());
    while(st < en) {
        int mid = (st + en + 1) / 2;
        if(solve(mid))
            st = mid;
        else
            en = mid - 1;
    }
    cout << st;
    
    return 0;
}
