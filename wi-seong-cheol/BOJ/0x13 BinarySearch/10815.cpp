//
//  .cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 6 3 2 10 -10
 8
 10 9 -5 2 3 4 5 -10
 [Output]
 1 0 0 1 1 0 0 1
 */
// 시간복잡도: O(nlogn)
// 최악시간: 3,000,000
// 난이도: Silver 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/10815

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, x;
vector<int> a;
vector<int> b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < m; i++)
        cout << binary_search(a.begin(), a.end(), b[i]) << ' ';
    
    return 0;
}
