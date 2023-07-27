//
//  15655.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/14.
//

/*
 [Input]
 4 2
 9 8 7 1
 [Output]
 1 7
 1 8
 1 9
 7 8
 7 9
 8 9 
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 256
// 난이도: Silver 3
// Timer: 5m
// Url: https://www.acmicpc.net/problem/15655

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> ans;
int a[9];

void func(int k, int cur) {
    if(k == m) {
        for(int x: ans)
            cout << x << ' ';
        cout << '\n';
        return;
    }
    
    for(int i = cur; i < n; i++) {
        ans.push_back(a[i]);
        func(k + 1, i + 1);
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    func(0, 0);
    
    return 0;
}
