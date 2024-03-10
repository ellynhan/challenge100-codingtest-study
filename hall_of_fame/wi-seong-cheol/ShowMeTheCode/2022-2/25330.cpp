//
//  25330.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/16.
//

/*
 [Input]
 5 5
 5 3 1 2 4
 10 10 10 10 10
 [Output]
 20
 */
// 시간복잡도: O(2^n)
// 최악시간: 1,048,576
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/25330

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int ans;
int n, k;
int a[21], p[21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> p[i];

    int w[1 << n];

    for(int i = 0; i < (1 << n); i++) {
        vector<int> v;
        int sumk = 0;
        w[i] = 0;

        for(int j = 0; j < n; j++) {
            if(((i >> j) & 1)) {
                v.push_back(a[j]);
                w[i] += p[j];
            }
        }
        sort(v.begin(), v.end());

        int len = int(v.size());
        for(int j = 0; j < len; j++) {
            sumk += (len - j) * v[j];
        }
        if(sumk > k) w[i] = 0;
    }

    for(int i = 0; i < (1 << n); i++) {
        if(ans < w[i]) ans = w[i];
    }
    cout << ans;

    return 0;
}
