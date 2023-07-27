//
//  24954.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/14.
//

/*
 [Input]
 4
 10 15 20 25
 2
 3 10
 2 20
 0
 1
 4 10
 1
 1 10
 [Output]
 36
 */
// 시간복잡도: O(n * 2^n)
// 최악시간: 10,240
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/24954

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
int n, m;
int ans = 0x7f7f7f7f;
int a[11];

int solve(vector<int> v, vector<vector<pair<int, int>>>& p) {
    int tmp[11];
    copy(a, a + n, tmp);
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(tmp[v[i]] > 0) sum += tmp[v[i]];
        else sum++;
    
        for(auto element: p[v[i]]) {
            tmp[element.X - 1] -= element.Y;
        }
    }
 
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<pair<int, int>>> p(n);
    for(int i = 0; i < n; i++) {
        cin >> m;
        while(m--) {
            int a, d; cin >> a >> d;
            p[i].push_back({a, d});
        }
    }
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        v[i] = i;
    do {
        ans = min(ans, solve(v, p));
    } while(next_permutation(v.begin(), v.end()));
    cout << ans;
    
    return 0;
}
