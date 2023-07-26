//
//  2632.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/13.
//

/*
 [Input]
 7
 5 3
 2
 2
 1
 7
 2
 6
 8
 3
 [Output]
 5
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2632

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int ans, n, m, k, val;
vector<int> a, b;
int sumA[3001], sumB[3001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> val;
        sumA[i] = sumA[i - 1] + val;
    }
    for(int i = n + 1; i <= 2 * n; i++)
        sumA[i] += sumA[i - n] + sumA[n];
    for(int i = 1; i <= m; i++) {
        cin >> val;
        sumB[i] = sumB[i - 1] + val;
    }
    for(int i = m + 1; i <= 2 * m; i++)
        sumB[i] += sumB[i - m] + sumB[m];
    for(int i = 1; i <= n; i++)
        for(int j = i; j < i + n - 1; j++)
            a.push_back(sumA[j] - sumA[i - 1]);
    for(int i = 1; i <= m; i++)
        for(int j = i; j < i + m - 1; j++)
            b.push_back(sumB[j] - sumB[i - 1]);
    a.push_back(sumA[n]);
    b.push_back(sumB[m]);
    a.push_back(0);
    b.push_back(0);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i <= k; i++) {
        auto p1 = equal_range(a.begin(), a.end(), i);
        auto p2 = equal_range(b.begin(), b.end(), k - i);
        ans += (p1.second - p1.first) * (p2.second - p2.first);
    }
    cout << ans;
    
    return 0;
}
