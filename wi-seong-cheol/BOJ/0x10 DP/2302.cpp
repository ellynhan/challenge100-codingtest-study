//
//  1463.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 9
 2
 4
 7
 [Output]
 12
 */
// 시간복잡도: O(n)
// 최악시간: 40
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2302

#include <iostream>
#include <vector>

using namespace std;
int n, m;
int d[41];
vector<int> v = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    v.push_back(n + 1);
    d[0] = 1; d[1] = 1; d[2] = 2;
    for(int i = 3; i <= n; i++) d[i] = d[i - 1] + d[i - 2];
    int ans = 1;
    for(int i = 1; i < v.size(); i++) ans *= d[v[i] - v[i - 1] - 1];
    cout << ans;
    
    return 0;
}
