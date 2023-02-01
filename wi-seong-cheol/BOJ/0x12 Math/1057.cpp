//
//  1057.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 16 1 2
 [Output]
 1
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1057

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, a, b, ans;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> a >> b;
    if(a > b) swap(a, b);
    for(int i = 1; i <= n; i++)
        v.push_back(i);
    while(v.size() > 1) {
        ans++;
        vector<int> nxt;
        for(int i = 0; i < v.size() - 1; i += 2) {
            cnt++;
            int x = v[i];
            int y = v[i + 1];
            if(x == a && y == b) {
                cout << ans;
                return 0;
            }
            if(y == a || y == b) nxt.push_back(y);
            else nxt.push_back(x);
        }
        if(v.size() % 2 == 1) nxt.push_back(v.back());
        v = nxt;
    }
    
    return 0;
}
