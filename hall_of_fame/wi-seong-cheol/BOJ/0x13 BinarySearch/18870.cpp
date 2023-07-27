//
//  18870.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 2 4 -10 4 -9
 [Output]
 2 3 0 3 1
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/18870

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> a;
vector<int> b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
        b.push_back(x);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for(int i = 0; i < n; i++)
        cout << lower_bound(b.begin(), b.end(), a[i]) - b.begin() << ' ';
        
    return 0;
}
