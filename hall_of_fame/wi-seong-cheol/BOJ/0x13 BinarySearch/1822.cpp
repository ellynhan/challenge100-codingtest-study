//
//  1822.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 3
 2 5 11 7
 9 7 4
 [Output]
 3
 2 5 11
 */
// 시간복잡도: O(nlogn)
// 최악시간: 3,000,000
// 난이도: Silver 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1822

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> a, b, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int x: a) {
        if(binary_search(b.begin(), b.end(), x)) continue;
        ans.push_back(x);
    }
    cout << ans.size() << '\n';
    for(int x: ans)
        cout << x << ' ';
    
    return 0;
}
